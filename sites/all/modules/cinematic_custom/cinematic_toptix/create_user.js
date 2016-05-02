(function($) {
  Drupal.behaviors.toptix = {
    attach: function(context, settings) {
      // closure variable
      var create_user = this.createUser;
      $('#' + settings.toptix_form).submit(function(event) {
        if ( $(this).find('input[name^="field_toptix"]').val() ) {
          return;
        }
        event.stopPropagation();
        create_user(this);
        return false;
      });
    },

    createUser: function(form) {
      Customer = {
        Login: {
          Name: 'drupal_' + $(form['name']).val(),
          Password: Math.random().toString(36).slice(-8), 
        },
        Name: {
          First: $(form['name']).val(),
          Last: '',
        },
        AddressDetails: []
      };
      Customer.AddressDetails[0] = {
        Address: {
          AddressLine1: "", 
          AddressLine2: "", 
          AddressLine3: "",
        },
        Usage: 10,
      };
      $esro.createCustomer(Customer, 'toptix_callback_save');
    }
  };
}) (jQuery);

var toptix_limit_calls = 0;
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
  var form = jQuery('#' + Drupal.settings.toptix_form);
  form.find('input[name^="field_toptix"]').val(result.Result.Id);
  form.submit();
}

function toptix_callback_create(result) {
  var Customer = result.Result;
  Customer.Login.Name = 'first2';
  Customer.Login.Password = 'first';
  Customer.ExternalId = 99;
  toptix_clean_customer(Customer);
  $esro.createCustomer(Customer, 'toptix_callback_save');
};

function toptix_clean_customer(obj) {
  delete obj.AddressDetails[0].Address.CountryName;
  delete obj.AddressDetails[0].Address.CountryId;
  delete obj.AddressDetails[0].Address.StateName;
  delete obj.AddressDetails[0].Address.StateId;
  delete obj.AddressDetails[0].Address.ZipCode;
  delete obj.AddressDetails[0].Address.CityId;
  delete obj.AddressDetails[0].Address.CityName;

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


