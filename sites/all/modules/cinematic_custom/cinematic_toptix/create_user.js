var toptix_form_processed = false;
var toptix_form_clicked = null;
(function($) {
  Drupal.behaviors.toptix = {
    attach: function(context, settings) {
      $('#' + settings.toptix_form + ' input[name="op"]').click(function(event) {
        toptix_form_clicked = this;
      });

      $('#' + settings.toptix_form).submit(function(event) {
        if (toptix_form_processed) {
          return;
        }
        toptix_form_data = this;
        toptix_form_item = $(this).find('input[name^="field_toptix"]');
        if (toptix_form_item.length == 0) {
          console.log('user toptix field not found');
          return;
        }
        var toptix_id = toptix_form_item.val();
        toptix_form_item.addClass('throbbing').css('background-repeat', 'no-repeat');
        event.stopPropagation();
        if (toptix_id) {
          $esro.customerLoginById(toptix_id, 'toptix_callback_user_login');
        }
        else {
          $esro.getEmptyCustomer('toptix_callback_create');
        }
        return false;
      });
    },
  };
}) (jQuery);

var toptix_limit_calls = 0;
var toptix_form_data = null;
var toptix_form_item = null;
function toptix_user_submit() {
  toptix_form_item.removeClass('throbbing');
  jQuery(toptix_form_clicked).click();
}

function toptix_callback_save(result) {
  if (toptix_limit_calls++ > 10) {
    toptix_form_processed = true;
    toptix_user_submit();
    return;
  }
  if (result.HasError) {
    toptix_form_item.val(result.ErrorDescription);
    toptix_form_processed = true;
    toptix_user_submit();
    return;
  }
  if (!('Id' in result.Result)) {
    $esro.getCustomerDetails('toptix_callback_save');
  }
  else {
    toptix_validated = true;
    toptix_form_item.val(result.Result.Id);
    toptix_form_processed = true;
    toptix_user_submit();
  }
}

function toptix_alter_customer(Customer, form) {
  Customer.Login.Name = 'drupal_' + form['name'].value;

  var value_checked = jQuery(form).find('input[name^="field_first_name"]').val();
  if (value_checked) {
    Customer.Name.First = value_checked;
  }
  var value_checked = jQuery(form).find('input[name^="field_last_name"]').val();
  if (value_checked) {
    Customer.Name.Last = value_checked;
  }

  var contact_details = [];
  contact_details[0] = jQuery(form).find('input[name^="field_landline"]').val();
  contact_details[1] = jQuery(form).find('input[name^="field_mobile"]').val();
  contact_details[3] = form['mail'].value;
  contact_details.forEach (function(value, idx) {
    if (value) {
      Customer.ContactDetails[idx].Detail = value;
    }
  });
    /*
    Customer.AddressDetails[0] = {
      Address: {
        AddressLine1: "", 
        AddressLine2: "", 
        AddressLine3: "",
      },
      Usage: 10,*/
  toptix_clean_customer(Customer);
}

function toptix_callback_create(result) {
  var form = toptix_form_data;
  var Customer = result.Result;
  toptix_alter_customer(Customer, form);
  Customer.Login.Password = Math.random().toString(36).slice(-8);
  $esro.createCustomer(Customer, 'toptix_callback_save');
};

function toptix_callback_user_login(result) {
  if (toptix_limit_calls++ > 10 || result.HasError) {
    toptix_form_processed = true;
    toptix_user_submit();
    return;
  }

  if ((typeof result.Result != 'object') || !('Id' in result.Result)) {
    $esro.getCustomerDetails('toptix_callback_user_login');
    return;
  }

  var form = toptix_form_data;
  var Customer = result.Result;
  toptix_alter_customer(Customer, form);
  $esro.updateCustomerDetails(Customer, function(result) {
    toptix_form_processed = true;
    toptix_user_submit();
  });
}



function toptix_clean_customer(obj) {
  delete obj.AddressDetails[0].Address.CountryName;
  delete obj.AddressDetails[0].Address.CountryId;
  delete obj.AddressDetails[0].Address.StateName;
  delete obj.AddressDetails[0].Address.StateId;
  delete obj.AddressDetails[0].Address.ZipCode;
  delete obj.AddressDetails[0].Address.CityId;
  delete obj.AddressDetails[0].Address.CityName;
  return;

  // ignored
  delete obj.AddressDetailIds;
  delete obj.AssociationIds;
  delete obj.Birthday;
  delete obj.BlackListItems;
  delete obj.ClientTypes;
  delete obj.ContactMeByServiceIds;
  delete obj.DataProtectionDetails;
  delete obj.DisplayName;
  delete obj.Gender;
  delete obj.Note;
  delete obj.OrganizationUnitIds;
  delete obj.PreferenceDetails;
  delete obj.PreferenceIds;
  delete obj.RelatedClients;
  delete obj.Remarks;
  delete obj.StronglyRelatedClients;
}

