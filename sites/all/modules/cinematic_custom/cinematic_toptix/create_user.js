(function($) {
  Drupal.behaviors.toptix = {
    attach: function(context, settings) {
      // closure variable
      $('#' + settings.toptix_form).submit(function(event) {
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
    return;
  }
  if (result.HasError) {
    var form = jQuery('#' + Drupal.settings.toptix_form);
    form.find('input[name^="field_toptix"]').val(result.ErrorDescription);
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
    form.submit();
  }
}

function toptix_callback_create(result) {
  var form = toptix_form_data;
  var Customer = result.Result;
  Customer.Login.Name = 'drupal_' + form['name'].value;
  Customer.Login.Password = 'eqdacz';
  //Password: Math.random().toString(36).slice(-8), 
  Customer.Name.First = form['name'].value;
  Customer.Name.Last = '';
    /*
    Customer.AddressDetails[0] = {
      Address: {
        AddressLine1: "", 
        AddressLine2: "", 
        AddressLine3: "",
      },
      Usage: 10,*/

  toptix_clean_customer(Customer);
  $esro.createCustomer(Customer, 'toptix_callback_save');
};

function toptix_callback_user_login(result) {
  if (toptix_limit_calls++ > 10 || result.HasError) {
    var form = jQuery('#' + Drupal.settings.toptix_form);
    form.submit();
    return;
  }

  if ((typeof result.Result != 'object') || !('Id' in result.Result)) {
    $esro.getCustomerDetails('toptix_callback_user_login');
    return;
  }

  var form = toptix_form_data;
  var Customer = result.Result;
  Customer.Name.First = form['name'].value;
  $esro.updateCustomerDetails(Customer, function(result) {
    var form = jQuery('#' + Drupal.settings.toptix_form);
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
  delete obj.ContactDetails;
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

