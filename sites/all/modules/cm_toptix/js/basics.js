
//function ShowClientDetails() {
// $("#create").dialog({ modal: true, width: "400", height: 800, title: 'Client Details' });
//}

(function($) {
 var params;
 params = $("#edit-field-username-und-0-value").val() + ";" + $("#edit-field-lastname-und-0-value").val() + ";";
 params += $("#edit-name").val() + ";" + $("#edit-pass-pass1").val() + ";";
 params += $("#edit-mail").val() + ";" + $("#edit-field-mobile-und-0-value").val() + ";";
 params += $("#edit-field-landline-und-0-value").val() + ";" + $("#edit-field-address-und-0-value").val() + ";";
 params += $("#edit-field-city-und-0-value").val() + ";" + $("#edit-field-zip-und-0-value").val();
 console.log(JSON.stringify(params));
 console.log(params);
 CreateCustomer(JSON.stringify(params), "#create");
})(jQuery);
/*
function CreateClient() {
 var params;
 params = $("#edit-field-username-und-0-value").val() + ";" + $("#edit-field-lastname-und-0-value").val() + ";";
 params += $("#edit-name").val() + ";" + $("#edit-pass-pass1").val() + ";";
 params += $("#edit-mail").val() + ";" + $("#edit-field-mobile-und-0-value").val() + ";";
 params += $("#edit-field-landline-und-0-value").val() + ";" + $("#edit-field-address-und-0-value").val() + ";";
 params += $("#edit-field-city-und-0-value").val() + ";" + $("#edit-field-zip-und-0-value").val();
 console.log(JSON.stringify(params));
 console.log(params);
 console.log( form_get_errors());
 CreateCustomer(JSON.stringify(params), "#create");

}*/