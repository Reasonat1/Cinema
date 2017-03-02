var toptix_form_incr = null;
var toptix_form_item = null;
var toptix_form_processed = false;
(function($) {
  $(document).ready(function() {
      $('form').submit(function(event) {
        if (toptix_form_processed) {
          return;
        }
        toptix_form_processed = true;

        toptix_form_item = $(this).find('input[name^="incr"]');
        toptix_form_incr = toptix_form_item.val();
        toptix_form_item.addClass('throbbing').css('background-repeat', 'no-repeat');
        event.stopPropagation();
        $esro.getEmptyCustomer('toptix_callback_create');
        return false;
      });
  });
}) (jQuery);

function toptix_callback_create(result) {
  var Customer = result.Result;
  var form_data = {incr: toptix_form_incr};
  toptix_alter_customer(Customer, form_data);
  Customer.Login.Password = Math.random().toString(36).slice(-8);
  $esro.createCustomer(Customer, 'toptix_callback_save');
};

function toptix_callback_save(result) {
  if (result.HasError) {
    jQuery('input[name="error"]').val(result.ErrorDescription);
  }
  else {
    toptix_form_item.removeClass('throbbing');
    jQuery('form').submit();
  }
}

function toptix_alter_customer(Customer, form) {
  Customer.Login.Name = 'example_test' + form['incr'].value;

  Customer.Name.First = Customer.Login.Name;
  Customer.Name.Last = Customer.Login.Name;

  var contact_details = [];
  contact_details[0] = '076553323';
  contact_details[1] = '0573322113';
  contact_details[3] = Customer.Login.Name + '@example_mail.com';
  contact_details.forEach (function(value, idx) {
    if (value) {
      Customer.ContactDetails[idx].Detail = value;
    }
  });
  toptix_clean_customer(Customer);
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

