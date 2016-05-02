//*****************************************************************************************************
//***********************************		Login
//*****************************************************************************************************

function GoLogin(user, pass) {
    if (user === undefined)
        user = $("#userr").val();
    if (pass === undefined)
        pass = $("#passs").val();
    $esro.customerLogin(user, pass, "loginCallback");
}
function loginCallback(data) {
    if (data.HasError) {
        alert("customerLogin: " + data.ErrorDescription);
        $("#updateClientDiv").css("display", "none")
    }
    else {

        $("#updateClientDiv").css("display", "block");
    }
}

//*****************************************************************************************************
//***********************************		LoginBy ID
//*****************************************************************************************************

function GoLoginById(guid) {
    if (guid === undefined)
        guid = $("#guidToLogin").val();

    $esro.customerLoginById(guid, "loginByIdCallback");
}
function loginByIdCallback(data) {
    if (data.HasError) {
        alert("customerLoginById: " + data.ErrorDescription);
        $("#updateClientDiv").css("display", "none")
    }
    else {

        $("#updateClientDiv").css("display", "block");
    }
}
//*****************************************************************************************************
//***********************************		Logout
//*****************************************************************************************************
function GoLogout() {
    $esro.customerLogout("logoutCallback");

}

function logoutCallback(result) {
    if (result.HasError) {
        alert("customerLogout: " + result.ErrorDescription);
        $("#updateClientDiv").css("display", "none")
    }
    else {
        $("#updateClientDiv").css("display", "none")
    }
}
//*****************************************************************************************************
//***********************************		Get client
//*****************************************************************************************************
function GetClient() {
    $esro.getCustomerDetails("getClientCallback1");

}
function getClientCallback1(result) {
    if (result.HasError) {
        alert("getClientCallback1: " + result.ErrorDescription);
        return;
    }
    else {
        var currClient;

        fullClient = result.Result;
        currClient = fullClient;
        delete currClient.__type;
        //delete currClient.type;
        try
        {
            $("#txtResult").html(JSONTree.create(currClient));
        }
        catch(e)
        {
            $("#txtResult").html(JSON.stringify(currClient));
        }
        $("#txtResult").dialog({ modal: true, width: "90%", height: "850", title: 'Client Details' });
        
    }
}


//*****************************************************************************************************
//***********************************		Update client
//*****************************************************************************************************
//Custom update customer call. This example only changes first/last name
function GoUpdate() {
    $esro.getCustomerDetails("getClientCallback");

}
function getClientCallback(result) {
    fullClient = result.Result;
    result.Result.Name.First = $("#firstName").val();
    result.Result.Name.Last = $("#lastName").val();
    $esro.updateCustomerDetails(result.Result, "updateClientCallback")
}

function updateClientCallback(result) {
    if (result.HasError) {
        alert("updateClientCallback: " + result.ErrorDescription);
    }
}
//*****************************************************************************************************
//***********************************		Create customer
//*****************************************************************************************************
var newCustomerParams;
function CreateCustomer(params, controlName) {
        newCustomerParams = params;
        $("#create").hide();
        $esro.getEmptyCustomer("getEmptyCustomerCallback");
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
function createCustomerCallback(result)
{
    if (result.HasError) {
        alert("createCustomer: " + result.ErrorDescription);
        return;
    }
}

//*****************************************************************************************************
//***********************************		Modify Customer 
//*****************************************************************************************************
function UpdateCustomer(lastName, firstName) {
    var result = $esro.customerLogin(username, password);

    if (result.HasError) {
        console.log("customerLogin: " + result.ErrorDescription);
        return;
    }
    result = $esro.getCustomerDetails();

    result.Result.Name.Last = lastName;
    result.Result.Name.First = firstName;

    //UPDATE DATA PROTECTION
    //var a = new Object();
    //a.LocalId = 1;
   // a.Answer = 30;
    //a.ClientId = "f3da9a32-11dd-4bd7-896b-109f5b27bb0b";
    //a.DataProtectionQuestionId = "f58b64ce-7222-4f9e-948c-a450ef1a2be7";
    //a.IssuerCompanyId = 1;

    result.Result.DataProtectionDetails[0] = a;

    var modified = $esro.updateCustomerDetails(result.Result)
    if (modified.HasError) {
        console.log("updateCustomerDetails: " + modified.ErrorDescription);
        return;
    }
    console.log("updateCustomerDetails: OK");
}

//*****************************************************************************************************
//***********************************		Get Preferences
//*****************************************************************************************************
function GetAllPreferences() {
    $esro.getPreferences("getPreferencesCallback");

}
var pereferences;
function getPreferencesCallback(result) {
    if (result.HasError) {
        alert("getPreferencesCallback: " + result.ErrorDescription);
    }
    else {
        pereferences = result.Result;
       // for (i = 0; i < customerHistory.length; i++) {
        //    delete customerHistory[i].__type;
        // }
        delete pereferences.__type;
        $("#txtResult").html(JSONTree.create(pereferences));
        $("#txtResult").dialog({ modal: true, width: "60%", height:"600", title: 'Preferences' });
    }

}
//*****************************************************************************************************
//***********************************		Get Data Protection
//*****************************************************************************************************
function GetAllDataProtection() {
    $esro.getDataProtection("getDataProtectionCallback");

}
var dataProt;
function getDataProtectionCallback(result) {
    if (result.HasError) {
        alert("getPreferencesCallback: " + result.ErrorDescription);
    }
    else {
        dataProt = result.Result;
        // for (i = 0; i < customerHistory.length; i++) {
        //    delete customerHistory[i].__type;
        // }
        delete dataProt.__type;
        $("#txtResult").html(JSONTree.create(dataProt));
        $("#txtResult").dialog({ modal: true, width: "60%", height: "600", title: 'DataProtection' });
    }

}
//*****************************************************************************************************
//***********************************		Get Customer History
//*****************************************************************************************************
function GetCustomerHistory() {
    $esro.getCustomerHistory("getCustomerHistoryCallback");

}
var customerHistory;
function getCustomerHistoryCallback(result) {
    if (result.HasError) {
        alert("getCustomerHistoryCallback: " + result.ErrorDescription);
    }
    else {
        customerHistory = result.Result;
        for (i = 0; i < customerHistory.length; i++) {
            delete customerHistory[i].__type;
        }
        $("#txtResult").html(JSONTree.create(customerHistory));
        $("#txtResult").dialog({ modal: true, width: "100%",height: "600", title: 'Customer History' });
    }
        
}
//*****************************************************************************************************
//***********************************		Reprint Transaction
//*****************************************************************************************************
function ReprintTransaction(trnId) {
    $esro.reprintTransaction(trnId, "ReprintTransactionCallback");

}

function ReprintTransactionCallback(result) {
    if (result.HasError) {
        alert("ReprintTransaction: " + result.ErrorDescription);
        return;
    }
    alert(result.Result);
}
//*****************************************************************************************************
//***********************************		Free specific tickets ";" delimitered
//*****************************************************************************************************
function FreeById(id, callback, doReturnTransaction) {
    if (typeof (doReturnTransaction) == 'undefined')
        doReturnTransaction = false;
    $esro.freeSpecificItems(id, "freeByIdCallback", doReturnTransaction);
//    $eSRO.siteBasePath = baseUrl;
//    $eSRO.api.call("TransactionController.RemoveBasketItem",
//                    { "itemId": id },
//                    { type: "get", dataType: "jsonp", jsonpCallback: "freeByIdCallback" },
//                    undefined);
}
//*****************************************************************************************************
//***********************************		Free specific area tickets 
//*****************************************************************************************************
function FreeByArea(eventId, areaId, callback, doReturnTransaction) {
    if (typeof (doReturnTransaction) == 'undefined')
        doReturnTransaction = false;
    $esro.freeSpecificArea(eventId, areaId, "freeByIdCallback", doReturnTransaction);
    //    $eSRO.siteBasePath = baseUrl;
    //    $eSRO.api.call("TransactionController.RemoveBasketItem",
    //                    { "itemId": id },
    //                    { type: "get", dataType: "jsonp", jsonpCallback: "freeByIdCallback" },
    //                    undefined);
}
function freeByIdCallback(result) {
    if (result.HasError) {
        alert("freeByIdCallback: " + result.ErrorDescription);
    }
    if(result.Result != null ) {
        basketHandler(result.Result);
    }
}
//*****************************************************************************************************
//***********************************		Auto Catch tickets
//*****************************************************************************************************
function CatchTicket(eventGuid, areaGuid, priceTypeId, priceLevelId, reservationType, seatCount) {
    $esro.autoCatchTickets(eventGuid, areaGuid, priceTypeId, priceLevelId, reservationType, seatCount, "catchTicketCallBack")
}
function catchTicketCallBack(result) {
    if (result.HasError) {
        alert("catchTicketCallBack: " + result.ErrorDescription);
    }
}

//*****************************************************************************************************
//***********************************		Add Coupon
//*****************************************************************************************************
function AddNewCoupon(couponPaymentId, couponId) {
    $esro.addCoupon("", couponId, couponPaymentId, "addCouponCallBack")
}
function addCouponCallBack(result) {
    if (result.HasError) {
        alert("addCouponCallBack: " + result.ErrorDescription);
    }
}
//*****************************************************************************************************
//***********************************		Add Voucher As Payment
//*****************************************************************************************************
function AddNewVoucher(voucherPaymentId, voucherId) {
    $esro.addVoucher("", voucherId, voucherPaymentId, "addVoucherCallBack")
}
function addVoucherCallBack(result) {
    if (result.HasError) {
        alert("addVoucherCallBack: " + result.ErrorDescription);
    }
}
//*****************************************************************************************************
//***********************************		Buy Voucher 
//*****************************************************************************************************
function BuyVoucher(voucherDefinitionId, quantity, price) {
    $esro.addVoucherItem(voucherDefinitionId, quantity, price, "buyVoucherCallBack")
}
function buyVoucherCallBack(result) {
    if (result.HasError) {
        alert("buyVoucherCallBack: " + result.ErrorDescription);
    }
}
//*****************************************************************************************************
//***********************************		Add Membership
//*****************************************************************************************************
function AddNewMembership(membershipdefinitionid, pricetypeid, quantity) {
    $esro.addMembership(membershipdefinitionid, pricetypeid, quantity, "addNewmembershipCallBack")
}
function addNewmembershipCallBack(result) {
    if (result.HasError) {
        alert("addNewmembershipCallBack: " + result.ErrorDescription);
    }
}
//AddNewmembership($("#membershipdefinitionid").val(), $("#pricetypeid").val(), $("#quantity").val());
//*****************************************************************************************************
//***********************************		Get Event Description
//*****************************************************************************************************
function GetEventDescription(evId)
{
    $esro.getEventDescription(evId, "getEventDescriptionCallback")
}
var latestEventDescription;
function getEventDescriptionCallback(result)
{
    if (result.HasError)
        alert("getEventDescriptionCallback: " + result.ErrorDescription);
    else {
        latestEventDescription = result.Result;
       
        $("#txtResult").html(JSONTree.create(latestEventDescription));
       
        $("#txtResult").dialog({ modal: true, width: "95%", height: "700",title: 'Event Description' });
        $("#eventGuid").val(latestEventDescription.Id);
        
        $("#areaGuid").val(latestEventDescription.Areas[0].Area.AreaGuid);
       // $("#areaGuid").replaceWith("<select id='areaGuid'/>");

        $.each(latestEventDescription.Areas, function(index, value) {
            var areaname = value.Area.Name.Value;
            var areaGuid = value.Area.AreaGuid;
            var currentOption = $("#areaGuid").append($('<option />',
            {
                value: areaGuid,
                text: areaname + " --- [" + areaGuid + "]",
                type: value.Area.DefaultSeatingType == 10 ? "GA" : "BA"
            }));
        });

        $.each(latestEventDescription.Pricing.PriceTypeAxis, function(index, value) {
        var pName = value.value;
        var pGuid = value.key;
        $("#priceTypeId").append($('<option/>', {
            value: pGuid,
            text: pName + " --- [" + pGuid + "]"
            }));
        });

        $.each(latestEventDescription.Pricing.PriceLevelAxis, function(index, value) {
        var pName = value.value;
        var pGuid = value.key;
        $("#priceLevelId").append($('<option/>', {
                value: pGuid,
                text: pName + " --- [" + pGuid + "]"
            }));
        });
        $("#reservationType").val($("#areaGuid option:selected").attr("type"));
    }
}
//*****************************************************************************************************
//***********************************		Obo Login
//*****************************************************************************************************
function OboLogin(userName, password) {
    $esro.oboLogin(userName, password, "OboLoginCallback");
}
function OboLoginCallback(result) {
    if (result.HasError) {
        alert("OboLogin-> OboLoginCallback: " + result.ErrorDescription);
    }
    else {
        alert("Current OBO: " + result.Result);
    }    
}

//*****************************************************************************************************
//***********************************		Obo Logout
//*****************************************************************************************************
function OboLogout() {
    $esro.oboLogout("OboLogOutCallback");
}
function OboLogOutCallback(result) {
    if (result.HasError) {
        alert("OboLogOutCallback: " + result.ErrorDescription);
    }
    else {
        alert("OboLogout-> Current OBO: " + result.Result);
    }
}
//*****************************************************************************************************
//***********************************		Get delivery methods
//*****************************************************************************************************
function GetDeliveryMethods() {
    $esro.getdeliverymethods("getdeliverymethodsCallback");
}
function getdeliverymethodsCallback(result) {
    if (result.HasError) {
        alert("getdeliverymethodsCallback: " + result.ErrorDescription);
    }
    else {
        $("#txtResult").html(JSONTree.create(result.Result));
        $("#txtResult").dialog({ modal: true, width: "60%", height: "500", title: 'Delivery Methods' });
    }
}

//*****************************************************************************************************
//***********************************		Add delivery to basket
//*****************************************************************************************************
//deliveryMethod is required.
//hasAddress means the the delivery item has an address attached.
//Use billing address will use the existing customer address.
//DeliveryState, DeliveryCountry should be the Id's (GUID) of existing entities
//
function AddDeliveryToBasket(deliveryMethod, hasAddress, useBillingAddress, DeliveryAddress, DeliveryAddress2, DeliveryAddress3, DeliveryCity, DeliveryZipCode, DeliveryState, DeliveryCountry) {
    $esro.addDeliveryToBasket(deliveryMethod, hasAddress, useBillingAddress, DeliveryAddress, DeliveryAddress2, DeliveryAddress3, DeliveryCity, DeliveryZipCode, DeliveryState, DeliveryCountry, "AddDeliveryToBasketCallback");
}
function AddDeliveryToBasketCallback(result) {
    if (result.HasError) {
        alert("getdeliverymethodsCallback: " + result.ErrorDescription);
    }
}
//*****************************************************************************************************
//***********************************		Close session
//*****************************************************************************************************


function CloseSession()
{
    $esro.closeSession("closeSessionCallback");
}
function closeSessionCallback(result) {
    if (result.HasError)
        alert("closeSessionCallback: " + result.ErrorDescription);
}

//*****************************************************************************************************
//***********************************		Change language
//*****************************************************************************************************

function ChangeCulture( cult) {
        if (cult === undefined)
        cult = $("#cult").val();
    $esro.setCulture(cult, "setCultureCallback");
}
function setCultureCallback(result) {
    if (result.HasError)
        alert("setCultureCallback: " + result.ErrorDescription);
    alert("Current culture is: " + result.Result);
}

//*****************************************************************************************************
//***********************************		Get Esro Cashed objects (entities)
//*****************************************************************************************************
function GetObjectsFromCache(cacheType) {

    $esro.getFromCache(cacheType, "getObjectsFromCacheCallback");
}
function getObjectsFromCacheCallback(result) {
    if (result.HasError) {
        alert("getObjectsFromCacheCallback: " + result.ErrorDescription);
    }
    else {
        items = result.Result;
        delete items.__type;
        
        $("#txtResult").html(JSONTree.create(items));
        $("#txtResult").dialog({ modal: true, width: "60%", height: "600", title: 'DataProtection' });
    }
}
//*****************************************************************************************************
//***********************************		Get Transaction
//*****************************************************************************************************
function GetCurrTransaction() {
    $esro.getCurrentTransaction("getTransactionCallbac");
}

function GetPrevTransaction() {
    $esro.getPreviousTransaction("getTransactionCallbac");
}

function getTransactionCallbac(result) {
    if (result.HasError) {
        alert("getTransactionCallbac: " + result.ErrorDescription);
    }
    else {
        items = result.Result;
        delete items.__type;
       
        $("#txtResult").html("");
        $("#txtResult").html(JSONTree.create(items));
        $("#txtResult").dialog({ modal: true, width: "60%", height: "600", title: 'DataProtection' });
    }
}

function DiscardTransaction() {
    $esro.discardTransaction("discardTransactionCallbac");
}

function discardTransactionCallbac(result) {
    if (result.HasError) {
        alert("discardTransactionCallbac: " + result.ErrorDescription);
    }
}

//********************************  Calls  ***********************************************
//var username = "user22";
//var password = "password22";
//var firstName = "ChangedFirstName";
//var lastName = "ChangedLastName";
//Login()
//CreateCustomer();
//UpdateCustomer();
//AutoCatch(10);
//FreeById(5);
//closeSession();
//DiscardTransaction()
