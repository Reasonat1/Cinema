//*****************************************************************************************************
//***********************************		Login
//*****************************************************************************************************
function GoLogin(user, pass) {
    if (user === undefined)
        user = $("#edit-name").val();
    if (pass === undefined)
        pass = $("#edit-pass").val();
    $esro.customerLogin(user, pass, "loginCallback");
}
function loginCallback(data) {
    if (data.HasError) {
        alert("customerLogin: " + data.ErrorDescription);
    }
    console.log(data);
	window.location.href="/";
}

//*****************************************************************************************************
//***********************************		Get client and Save Toptix Id in DB
//*****************************************************************************************************
function GetClient() {
    $esro.getCustomerDetails("getClientCallback1");

}
function getClientCallback1(result) {

    if (result.HasError) {
        alert("getClientCallback1: " + result.ErrorDescription);
        return;
    }

    var currClient;

    fullClient = result.Result;
    var currClient = fullClient;
    console.dir(currClient);
    delete currClient.__type;
    console.dir(currClient.AddressDetails[0]);
    var toptix_id = currClient.AddressDetails[0].ClientId;
    var mail = currClient.ContactDetails[3].Detail;

    $.ajax({
        method: "POST",
        url: 'http://jer-cin.tikkewebsites.com/toptix_integration',
        data: { ajax_toptix_id: toptix_id, email: mail},
        success: function(data) {
            console.log(data);
        }
    });

}


var newCustomerParams;
function CreateCustomer(params, controlName) {

    //console.log('step1');
    newCustomerParams = params;
    //$("#create").hide();
    $esro.getEmptyCustomer("getEmptyCustomerCallback");
    //window.location.href = '/public_html';
}

function getEmptyCustomerCallback(result)
{
    if (result.HasError) {
        alert("getEmptyCustomer: " + result.ErrorDescription);
        return;
    }

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
    console.dir(result);
    var userLogin = result.Result.Login.Name;
    var userPass = result.Result.Login.Password;
    console.log(userLogin + " " + userPass);
    GoLogin(userLogin, userPass);
	
	if (result.HasError) {
        alert("createCustomer: " + result.ErrorDescription);
        return;
    }
}


//*****************************************************************************************************
//***********************************		Login and Update client
//*****************************************************************************************************

var detialsArry;
function UpdateClient(detials) {

    detialsArry = detials.split(";");
    var t_id = detialsArry[0];
    GoLoginByIdForUpdateClient(t_id);
}


function GoLoginByIdForUpdateClient(guid) {
    if (guid === undefined) {
        guid = $("#guidToLogin").val();
    }
    $esro.customerLoginById(guid, "loginByIdCallback");
}

function loginByIdCallback(data) {
    if (data.HasError) {
        alert("customerLoginById: " + data.ErrorDescription);
        //$("#updateClientDiv").css("display", "none")
    } else {
        $esro.getCustomerDetails("getClientCallback");
    }
}

function getClientCallback(result) {
    fullClient = result.Result;

    //If current password is not empty
    if (detialsArry[4] != "") {
        result.Result.Login.Password = detialsArry[4];
    }

    result.Result.Name.First = detialsArry[1];
    result.Result.Name.Last = detialsArry[2];
    result.Result.Login.Name = detialsArry[3];
    result.Result.ContactDetails[3].Detail = detialsArry[5];
    result.Result.ContactDetails[1].Detail = detialsArry[6];
    result.Result.ContactDetails[0].Detail = detialsArry[7];
    result.Result.AddressDetails[0].Address.AddressLine1 = detialsArry[8];
    result.Result.AddressDetails[0].Address.CityName[result.Result.AddressDetails[0].Address.CityName.CurrentLCID] = detialsArry[9];
    result.Result.AddressDetails[0].Address.ZipCode = detialsArry[9];

    console.dir(result.Result);

    $esro.updateCustomerDetails(result.Result, "updateClientCallback");
}

function updateClientCallback(result) {
    if (result.HasError) {
        alert("updateClientCallback: " + result.ErrorDescription);
    }
}
//********************************  Calls  ***********************************************
//CreateCustomer();