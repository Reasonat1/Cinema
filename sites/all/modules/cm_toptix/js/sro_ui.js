var newCustomerParams;
function CreateCustomer(params, controlName) {

    console.log('step1');
    newCustomerParams = params;
    //$("#create").hide();
    $esro.getEmptyCustomer("getEmptyCustomerCallback");
}

function getEmptyCustomerCallback(result)
{
    if (result.HasError) {
        alert("getEmptyCustomer: " + result.ErrorDescription);
        return;
    }
/*
    var paramsArry = newCustomerParams.split(";");
    console.log(paramsArry);
    var emptyCust = result.Result;
    emptyCust.Name.First = "first102";
    emptyCust.Name.Last = "last102";
    emptyCust.Login.Name = "TEST102";
    emptyCust.Login.Password = "TEST102";
    emptyCust.ContactDetails[3].Detail = "vlad94009277@gmail.com";
    emptyCust.ContactDetails[1].Detail = "04787";
    emptyCust.ContactDetails[0].Detail = "1515";
    emptyCust.AddressDetails[0].Address.AddressLine1 = "TEST";
    emptyCust.AddressDetails[0].Address.CityName[emptyCust.AddressDetails[0].Address.CityName.CurrentLCID] = "TESTC";
    emptyCust.AddressDetails[0].Address.ZipCode = "4747";
    console.log(emptyCust.ContactDetails[3].Detail);
    */
    var paramsArry = newCustomerParams.split(";");
    var emptyCust = result.Result;
    emptyCust.Name.First = paramsArry[0];
    emptyCust.Name.Last = paramsArry[1];
    emptyCust.Login.Name = paramsArry[2];
    emptyCust.Login.Password = paramsArry[3];
    emptyCust.ContactDetails[3].Detail = paramsArry[4];
    emptyCust.ContactDetails[1].Detail = paramsArry[5];
    emptyCust.ContactDetails[0].Detail = paramsArry[6];
    emptyCust.AddressDetails[0].Address.AddressLine1 = paramsArry[7];
    emptyCust.AddressDetails[0].Address.CityName[emptyCust.AddressDetails[0].Address.CityName.CurrentLCID] = paramsArry[8];
    emptyCust.AddressDetails[0].Address.ZipCode = paramsArry[9];

    delete (emptyCust.AddressDetails[0].Address.StateName);
    delete (emptyCust.AddressDetails[0].Address.StateId);
    delete (emptyCust.AddressDetails[0].Address.CountryName);
    delete (emptyCust.AddressDetails[0].Address.CountryId);

    $esro.createCustomer(emptyCust, "createCustomerCallback");
}
function createCustomerCallback(result){
    console.log('step3');
    var a = $esro.getCustomerDetails();
    if (result.HasError) {
        alert("createCustomer: " + result.ErrorDescription);
        return;
    }

}

//********************************  Calls  ***********************************************
//CreateCustomer();