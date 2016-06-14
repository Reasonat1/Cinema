var toptix_form_processed = false;

(function($) {
  Drupal.behaviors.toptix = {
    attach: function(context, settings) {
      // closure variable
      $('#' + settings.toptix_form).submit(function(event) {
        if (toptix_form_processed) {
          return;
        }
        toptix_form_data = this;
        var toptix_id = $(this).find('input[name^="field_toptix"]').val();
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

function toptix_callback_save(result) {
  if (toptix_limit_calls++ > 10) {
    toptix_form_processed = true;
    return;
  }
  if (result.HasError) {
    var form = jQuery('#' + Drupal.settings.toptix_form);
    form.find('input[name^="field_toptix"]').val(result.ErrorDescription);
    toptix_form_processed = true;
    form.submit();
    return;
  }
  if (!('Id' in result.Result)) {
    $esro.getCustomerDetails('toptix_callback_save');
  }
  else {
    toptix_validated = true;
    var form = jQuery('#' + Drupal.settings.toptix_form);
    form.find('input[name^="field_toptix"]').val(result.Result.Id);
    toptix_form_processed = true;
    form.submit();
  }
}

function toptix_alter_customer(Customer, form) {
  Customer.Login.Name = 'drupal_' + form['name'].value;

  Customer.Name.First = jQuery(form).find('input[name^="field_first_name"]').val();
  Customer.Name.Last = jQuery(form).find('input[name^="field_last_name"]').val();

  Customer.ContactDetails[0].Detail = jQuery(form).find('input[name^="field_landline"]').val();
  Customer.ContactDetails[1].Detail = jQuery(form).find('input[name^="field_mobile"]').val();
  Customer.ContactDetails[3].Detail = form['mail'].value;
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
  Password: Math.random().toString(36).slice(-8), 
  $esro.createCustomer(Customer, 'toptix_callback_save');
};

function toptix_callback_user_login(result) {
  if (toptix_limit_calls++ > 10 || result.HasError) {
    var form = jQuery('#' + Drupal.settings.toptix_form);
    toptix_form_processed = true;
    form.submit();
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
    var form = jQuery('#' + Drupal.settings.toptix_form);
    toptix_form_processed = true;
    form.submit();
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

