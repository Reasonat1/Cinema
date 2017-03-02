var eSRO_private = function() {

    //private member which holds the session state
    var sessionState = { status: "n/a", clientDetails: null, basket: null, contextId: null, OboName: null };
    var eventHandlers = { sessionStatusChanged: [], clientDetailsChanged: [], basketChanged: [], error: [], navigationRequired: [], oboChanged: []};
    var esroWindow = null;
    var baseURL = null;
    var integrationURL = "Iframe/IframeIntegration.ashx";
    var me = this;
    //var couponMethodId = "20000000-0000-0000-0000-000000000010";
    //var voucherMethodId = "20000000-0000-0000-0000-000000000008";

    function onStatusChanged(handlersContainer, statusObject) {
        for (var i = 0; i < handlersContainer.length; i++) {
            handlersContainer[i](statusObject);
        }
    };

    //-------------------------------------------------------------------------------------------------------------
    function onEsroWindowNavigation() {
        //checks if there are handlers in eventHandlers.clientDetailsChanged and eventHandlers.basketChanged and
        //calls getSessionState with "clientDetails" and/or "basket" accordingly
        //finally, calls updateSessionState()

        if (eventHandlers.basketChanged.length == 0 && eventHandlers.clientDetailsChanged.length == 0 && eventHandlers.sessionStatusChanged == 0 && eventHandlers.navigationRequired.length == 0 && eventHandlers.oboChanged.length == 0)
            return;

        if (esroWindow.attr("src").toLowerCase().indexOf("default.aspx") > -1) {
            if (eventHandlers.navigationRequired.length > 0) {
                for (var i = 0; i < eventHandlers.navigationRequired.length; i++) {
                    eventHandlers.navigationRequired[i]("");
                }
            }
        }
        generateStateEntity(false);
    };
    function rndString(len) {
        var str = '';
        var s = '0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM';
        for (var i = 0; i < len; i++)
            str += s.charAt(Math.floor((Math.random() * 100) % s.length));
        return str;
    }
    function postXDomain(url, data, callback) {
        if (baseURL == null)
            baseURL = findUrl();

        var msgIfr = jQuery("<iframe name='msgIfr' style='display:none'>");
        jQuery("body").append(msgIfr);
        msgIfr.load(ifrLoaded);
        var key = rndString(5);
        //var fieldsStr = ""
        var form = jQuery("<form>")
        .attr("target", "msgIfr")
        .attr("method", "post")
        .attr("action", baseURL + "Iframe/processPostData.ashx?jsonp=GenericCallback&key=" + encodeURIComponent(key) + "&url=" + encodeURIComponent(url));
        for (d in data) {
            form.append(
                jQuery("<input type='hidden' >").attr("name", d).attr("value", data[d])
            );
        }

        jQuery("body").append(form);
        form.submit();

        //jQuery.getScript("http://localhost/esro/net/site/Iframe/getPostResponse.ashx?key=" + encodeURIComponent(key), onSuccess);

        function ifrLoaded(e) {
            if (baseURL == null)
                baseURL = findUrl();
            //console.log('iframe loaded');
            form.remove();
            msgIfr.remove();

            jQuery.getScript(baseURL + "Iframe/getPostResponse.ashx?key=" + encodeURIComponent(key), onSuccess);
        }

        function onSuccess() {
            //console.log('success');
            if ((typeof callback) != "undefined")
                callback.call(null, arguments);
        }
    }


    //-------------------------------------------------------------------------------------------------------------
    this.createFrame = function(url, options, parent) {
        // creates an iFrame with the proper URL and proper options as attributes
        var iframeElement = jQuery("<iframe />");
        iframeElement.attr(options).attr("src", url);
        if (options.backgroundTransparet == "true") {
            iframeElement.attr("allowTransparency", "true").attr("bgcolor", "Transparent");
        }
        else {
            iframeElement.attr("allowTransparency", "false");
        }
        if (options.css) {
            iframeElement.attr("class", options.css);
        }
        return iframeElement;
    };

    //-------------------------------------------------------------------------------------------------------------
    function processEsroMl() {
        // looks for <esro: /> elements and process them according to their type
        var siteIframe = jQuery("esro\\:frame");
        if (siteIframe.length == 0)
            siteIframe = jQuery("frame").filter(function() { return this.scopeName == "esro" }); //support for IE pre-8
        if (siteIframe.length == 0)
            return;
        if (siteIframe.length > 1) {
            alert('esro:frame element is allowed only once per document');
            return;
        }
        var options =
        {
            id: siteIframe.attr("id"),
            width: siteIframe.attr("width"),
            height: siteIframe.attr("height"),
            backgroundTransparet: siteIframe.attr("backgroundTransparet"),
            frameborder: siteIframe.attr("frameborder"),
            css: siteIframe.attr("class")
        };
        esroWindow = me.createFrame(siteIframe.attr("href"), options, siteIframe.offsetParent());
        esroWindow.load(onEsroWindowNavigation);
        siteIframe.replaceWith(esroWindow);
    }

    //-------------------------------------------------------------------------------------------------------------
    function findUrl() {
        var scriptElement = jQuery('script').filter(function(index) {
            return this.src.match(/eSrojsapi.js$/i) != null;
        });
        if (scriptElement.length == 0) {
            return;
        }
        var src = scriptElement.attr('src');
        return src.substr(0, src.length - 19);
    }

    //-------------------------------------------------------------------------------------------------------------
    function generateJson2Script() {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.getScript(baseURL + 'js/json2.js');
    }

    //-------------------------------------------------------------------------------------------------------------
    function generateStateEntity(noNav) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.getScript(baseURL + integrationURL + "?jsonp=a123" + (noNav == true ? "&noNav=true" : "")); //?d=' + Date().valueOf().toString());
    }

    //-------------------------------------------------------------------------------------------------------------
    this.discardTransaction = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=discardTransaction' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        //success: onsuccess,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.closeSession = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=closesession' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        //success: onsuccess,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
            );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.getCurrentTransaction = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=getcurrenttransaction' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        //success: onsuccess,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
            );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.getPreviousTransaction = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=getprevioustransaction' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        //success: onsuccess,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
            );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.freeSpecificItems = function(itemsList, callback, doReturnTransaction) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=FreeItems&items=' + itemsList + '&doreturntransaction=' + doReturnTransaction.toString() + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.freeSpecificArea = function(eventId, areaId, callback, doReturnTransaction) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=freearea&eventId=' + eventId + '&areaId=' + areaId + '&doreturntransaction=' + doReturnTransaction.toString() + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.autoCatchTickets = function(eventGuid, areaGuid, priceTypeId, priceLevelId, reservationType, seatCount, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=autoCatchTickets&eventGuid=' + eventGuid + "&areaGuid=" + areaGuid + "&priceTypeId="
                            + priceTypeId + "&priceLevelId=" + priceLevelId + "&reservationType=" + reservationType + "&seatCount="
                            + seatCount + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.addCoupon = function(couponDefinitionId, couponId, couponMethodId, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
        {
            url: baseURL + integrationURL + '?action=handlecoupon&CouponId=' + couponId
                                            + "&CouponNameId=" + couponDefinitionId
                                            + "&MethodId=" + couponMethodId
                                            + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
            async: false,
            dataType: "jsonp",
            jsonp: false,
            jsonpCallback: "GenericCallback"
        }
    );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.addVoucher = function(voucherDefinitionId, voucherId, voucherMethodId, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
        {
            url: baseURL + integrationURL + '?action=handlegiftvoucher&VoucherNumber=' + voucherId
                                            + "&VoucherDefinitionId=" + voucherDefinitionId
                                            + "&MethodId=" + voucherMethodId
                                            + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
            async: false,
            dataType: "jsonp",
            jsonp: false,
            jsonpCallback: "GenericCallback"
        }
    );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.addVoucherItem = function(voucherDefinitionId, quantity, price, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
        {
            url: baseURL + integrationURL + '?action=addiftvoucher'
                                            + "&definitionid=" + voucherDefinitionId
                                            + "&qty=" + quantity
                                            + "&price=" + price
                                            + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
            async: false,
            dataType: "jsonp",
            jsonp: false,
            jsonpCallback: "GenericCallback"
        }
    );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.addMembership = function(membershipdefinitionid, pricetypeid, quantity, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
        {
            url: baseURL + integrationURL + '?action=addmembership&membershipdefinitionid=' + membershipdefinitionid
                                            + "&pricetypeid=" + pricetypeid
                                            + "&quantity=" + quantity
                                            + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
            async: false,
            dataType: "jsonp",
            jsonp: false,
            jsonpCallback: "GenericCallback"
        }
    );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.customerLogin = function(userName, password, callback) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=Login&username=' + encodeURIComponent(userName) + "&password=" + encodeURIComponent(password) + '&CustomCallback='
                        + callback + '&jsonp=GenericCallback',
                        async: false,
                        //success: onsuccess,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.customerLoginById = function(guid, callback) {
        if (baseURL == null)
            baseURL = findUrl();

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=loginbyid&ClientID=' + guid + '&CustomCallback='
                        + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.customerLogout = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();

        var result;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=Logout&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );

    }

    //-------------------------------------------------------------------------------------------------------------
    this.getCustomerDetails = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var result;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=getcustomerdetails' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );

    }

    //-------------------------------------------------------------------------------------------------------------
    this.updateCustomerDetails = function(customerObj, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        postXDomain(
                        "~/Iframe/IframeIntegration.ashx",
                        {
                            action: "updatecustomerdetails",
                            CustomerData: JSON.stringify(customerObj),
                            CustomCallback: callback
                        }
                    );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.getEmptyCustomer = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=getemptycustomer' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.getPreferences = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=getpreferences' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }


    //-------------------------------------------------------------------------------------------------------------

    this.getDataProtection = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=getdataprotection' + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }


    //-------------------------------------------------------------------------------------------------------------
    this.getEventDescription = function(eventId, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=geteventdescription&eventId=' + eventId + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }


    //-------------------------------------------------------------------------------------------------------------
    this.createCustomer = function(customerObj, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        postXDomain(
                        "~/Iframe/IframeIntegration.ashx",
                        {
                            action: "createcustomer",
                            CustomerData: JSON.stringify(customerObj),
                            CustomCallback: callback
                        }
                    );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.oboLogin = function(username, password, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=obologin&oboUsername=' + username + '&oboPassword=' + password + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
                );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.oboLogout = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=obologout&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
             );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.getCustomerHistory = function(callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
                    {
                        url: baseURL + integrationURL + '?action=loadclienthistory&CustomCallback=' + callback + '&jsonp=GenericCallback',
                        async: false,
                        dataType: "jsonp",
                        jsonp: false,
                        jsonpCallback: "GenericCallback"
                    }
             );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.reprintTransaction = function(tranId, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
                {
                    url: baseURL + integrationURL + '?action=reprint&tranToReturnId=' + tranId + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                    async: false,
                    dataType: "jsonp",
                    jsonp: false,
                    jsonpCallback: "GenericCallback"
                }
         );
    }

    //-------------------------------------------------------------------------------------------------------------
    this.setCulture = function(culture, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
                {
                    url: baseURL + integrationURL + '?action=setculture&culture=' + culture + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                    async: false,
                    dataType: "jsonp",
                    jsonp: false,
                    jsonpCallback: "GenericCallback"
                }
         );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.getFromCache = function(cachetypename, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
            {
                url: baseURL + integrationURL + '?action=getfromcache&cachetypename=' + cachetypename + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                async: false,
                dataType: "jsonp",
                jsonp: false,
                jsonpCallback: "GenericCallback"
            }
        );
    }
    //-------------------------------------------------------------------------------------------------------------
    this.getJsonFeed = function(feedName, callback) {
        if (baseURL == null)
            baseURL = findUrl();
        jQuery.ajax(
            {
                type: "GET",
                url: baseURL + "feed/" + feedName + "?json&callback=" + callback,
                dataType: "jsonp",
                jsonp: false,
                jsonpCallback: callback,
                success: function(response) {
                    console.log(response); // server response
                }
                
            }
        );
        //jQuery.getJSON(baseURL + "feed/" + feedName + "?json", callback);
    }
    //-------------------------------------------------------------------------------------------------------------

    this.getdeliverymethods = function(callback) 
    {
         if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
            {
                url: baseURL + integrationURL + '?action=getdeliverymethods&CustomCallback=' + callback + '&jsonp=GenericCallback',
                async: false,
                dataType: "jsonp",
                jsonp: false,
                jsonpCallback: "GenericCallback"
            });
    }
    //-------------------------------------------------------------------------------------------------------------
    this.joincontext = function(contextid, callback) 
    {
         if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
            {
                url: baseURL + integrationURL + '?action=joincontext&contextid=' + contextid + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                async: false,
                dataType: "jsonp",
                jsonp: false,
                jsonpCallback: "GenericCallback"
            });
    }
    //-------------------------------------------------------------------------------------------------------------
    
    this.getservertransaction = function(transactionid, callback) 
    {
         if (baseURL == null)
            baseURL = findUrl();
        var updateResult;

        jQuery.ajax(
            {
                url: baseURL + integrationURL + '?action=getservertransaction&transactionid=' + transactionid + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
                async: false,
                dataType: "jsonp",
                jsonp: false,
                jsonpCallback: "GenericCallback"
            });
    }
    //-------------------------------------------------------------------------------------------------------------
    
    this.addDeliveryToBasket = function(deliveryMethod, hasAddress, useBillingAddress, DeliveryAddress, DeliveryAddress2, DeliveryAddress3, DeliveryCity, DeliveryZipCode, DeliveryState, DeliveryCountry, callback) 
    {
    if (baseURL == null)
        baseURL = findUrl();
    var updateResult;

    jQuery.ajax(
    {
        url: baseURL + integrationURL + '?action=adddelivery&DeliveryMethod=' 
        + deliveryMethod + '&hasAddress=' 
        + hasAddress + '&UseBillingAddress=' 
        + useBillingAddress 
         + '&DeliveryAddress=' + DeliveryAddress 
         + '&DeliveryAddress2=' + DeliveryAddress2 
          + '&DeliveryAddress3=' + DeliveryAddress3 
           + '&DeliveryCity=' + DeliveryCity 
            + '&DeliveryZipCode=' + DeliveryZipCode 
             + '&DeliveryState=' + DeliveryState 
             + '&DeliveryCountry=' + DeliveryCountry
             + '&CustomCallback=' + callback + '&jsonp=GenericCallback',
        async: false,
        dataType: "jsonp",
        jsonp: false,
        jsonpCallback: "GenericCallback"
    });
    }
    //addDeliveryToBasket: function(deliveryMethod, hasAddress, callback) adddelivery
    //-------------------------------------------------------------------------------------------------------------
    this.initialize = function() {
        processEsroMl();
        generateJson2Script();
        if (sessionState.status == 'n/a' && esroWindow == null)
            return;
        generateStateEntity(true);
    };

    //-------------------------------------------------------------------------------------------------------------
    this.callNavigate = function(state) {
        onStatusChanged(eventHandlers.navigationRequired, state);
    }

    //-------------------------------------------------------------------------------------------------------------
    this.updateSessionState = function(state) {
        //private function used to update the ~sessionState~;
        //if sessionState.status changes its value (from "n/a" to "active" or vice versa) then the "sessionStatusChanged" event is raised (i.e. the onSessionStatusChanged called)
        //if sessionState.clientDetails changes its value (from null to not null or vice versa) then the "clientDetailsChanged" event is raised (i.e. the onClientDetailsChanged called)
        //if sessionState.basket changes its value (from null to not null or vice versa) then the "basketChanged" event is raised (i.e. the onBasketChanged called)
        sessionState.contextId = state.contextId;
        if (state == null)
            return;
        if (typeof (state.description) != 'undefined') {
            onStatusChanged(eventHandlers.error, state.description);
            return;
        }
        if (sessionState.status != state.status) {
            sessionState.status = state.status;
            onStatusChanged(eventHandlers.sessionStatusChanged, sessionState.status);
            //onSessionStatusChanged();
        }

        if (JSON.stringify(state.clientDetails) != JSON.stringify(sessionState.clientDetails)) {
            sessionState.clientDetails = state.clientDetails;
            onStatusChanged(eventHandlers.clientDetailsChanged, sessionState.clientDetails);
            //onClientDetailsChanged();
        }

        if (JSON.stringify(state.basket) != JSON.stringify(sessionState.basket)) {
            sessionState.basket = state.basket;
            onStatusChanged(eventHandlers.basketChanged, sessionState.basket);
            //onBasketChanged();
        }
        if (JSON.stringify(state.OboName) != JSON.stringify(sessionState.OboName)) {
            sessionState.OboName = state.OboName;
            onStatusChanged(eventHandlers.oboChanged, sessionState.OboName);
            //oboChanged();
        }
    }

    //-------------------------------------------------------------------------------------------------------------
    this.attachEventHandler = function(eventType, handler) {
        switch (eventType) {
            case 'basketChanged':
                eventHandlers.basketChanged[eventHandlers.basketChanged.length] = handler;
                break;
            case 'clientDetailsChanged':
                eventHandlers.clientDetailsChanged[eventHandlers.clientDetailsChanged.length] = handler;
                break;
            case 'sessionStatusChanged':
                eventHandlers.sessionStatusChanged[eventHandlers.sessionStatusChanged.length] = handler;
                break;
            case 'navigationRequired':
                eventHandlers.navigationRequired[eventHandlers.navigationRequired.length] = handler;
                break;
            case 'error':
                eventHandlers.error[eventHandlers.error.length] = handler;
                break;
            case 'oboChanged':
                eventHandlers.oboChanged[eventHandlers.oboChanged.length] = handler;
                break;
            default:
                return "eventType '" + eventType + "' is not supported.";
        }
    }

    //-------------------------------------------------------------------------------------------------------------
    this.gotoUrl = function(url) {
        if (esroWindow == null)
            return;
        esroWindow.attr('src', url);
    }

    //-------------------------------------------------------------------------------------------------------------
    this.getSessionState = function() {
        return sessionState;
    }

}
//-------------------------------------------------------------------------------------------------------------

//----------------------------              End of _private class                      ------------------------

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

//----------------------------               Begin $esro class                      ---------------------------

//-------------------------------------------------------------------------------------------------------------
var $esro = {
    version: "4.1", //the version of the API interface
    _private: new eSRO_private(),

    createWindow: function(url, options, parentElement) {
        //*************************     validate options
        //*************************     options.type=["iframe"|"window"]
        //*************************     other members are translated into either iframe attributes if the type=iframe or into window options if the type is window

        //*************************     when the window(regular or iframe) is created, its url is set to ~url~

        //*************************     parentElement is either an element object or jQuerySelector.
        //*************************     if type="iframe" and parentElement is not "undefined" then the iframe is appended to the parentElement
        return $esro._private.createFrame(url, options, parentElement);
    },

    //-------------------------------------------------------------------------------------------------------------
    /// returns the current session state
    getSessionState: function() {
        return $esro._private.getSessionState();
    },


    //-------------------------------------------------------------------------------------------------------------
    attachEventHandler: function(eventType, handler) {
        //eventType=["basketChanged" | "clientDetailsChanged", "sessionStatusChanged"]
        //when (and only when) one or more handlers are attached using this function then the "onload" event of the eSRO windows (if it was created)
        //will be handled by onEsroWindowNavigation() in order to request session state updates using updateSessionState().
        $esro._private.attachEventHandler(eventType, handler);
    },

    //-------------------------------------------------------------------------------------------------------------
    gotoUrl: function(url) {
        $esro._private.gotoUrl(url);
    },
    //-------------------------------------------------------------------------------------------------------------
    discardTransaction: function(callback) {
        $esro._private.discardTransaction(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    closeSession: function(callback) {
        $esro._private.closeSession(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getCurrentTransaction: function(callback) {
        $esro._private.getCurrentTransaction(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getPreviousTransaction: function(callback) {
        $esro._private.getPreviousTransaction(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    freeSpecificItems: function(itemsList, callback, doReturnTransaction) {
        $esro._private.freeSpecificItems(itemsList, callback, doReturnTransaction);
    },
    //-------------------------------------------------------------------------------------------------------------
    freeSpecificArea: function(eventId, areaId, callback, doReturnTransaction) {
    $esro._private.freeSpecificArea(eventId, areaId, callback, doReturnTransaction);
    },

    //-------------------------------------------------------------------------------------------------------------
    autoCatchTickets: function(eventGuid, areaGuid, priceTypeId, priceLevelId, reservationType, seatCount, callback) {
        $esro._private.autoCatchTickets(eventGuid, areaGuid, priceTypeId, priceLevelId, reservationType, seatCount, callback);
    },

    //-------------------------------------------------------------------------------------------------------------
    addCoupon: function(couponDefinitionId, couponId, couponMethodId, callback) {
        $esro._private.addCoupon(couponDefinitionId, couponId, couponMethodId, callback);
    },

    //-------------------------------------------------------------------------------------------------------------
    addVoucher: function(voucherDefinitionId, voucherId, voucherMethodId, callback) {
        $esro._private.addVoucher(voucherDefinitionId, voucherId, voucherMethodId, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    addVoucherItem: function(voucherDefinitionId, quantity, price, callback) {
        $esro._private.addVoucherItem(voucherDefinitionId, quantity, price, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    addMembership: function(membershipdefinitionid, pricetypeid, quantity, callback) {
        $esro._private.addMembership(membershipdefinitionid, pricetypeid, quantity, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    customerLogin: function(userName, password, callback) {
        $esro._private.customerLogin(userName, password, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    customerLoginById: function(customerGuid, callback) {
        $esro._private.customerLoginById(customerGuid, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    customerLogout: function(callback) {
        $esro._private.customerLogout(callback);
    },

    //-------------------------------------------------------------------------------------------------------------
    getCustomerDetails: function(callback) {
        $esro._private.getCustomerDetails(callback);
    },

    //-------------------------------------------------------------------------------------------------------------
    updateCustomerDetails: function(customerObj, callback) {
        $esro._private.updateCustomerDetails(customerObj, callback);
    },

    //-------------------------------------------------------------------------------------------------------------
    getEmptyCustomer: function(callback) {
        $esro._private.getEmptyCustomer(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getPreferences: function(callback) {
        $esro._private.getPreferences(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getDataProtection: function(callback) {
        $esro._private.getDataProtection(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    createCustomer: function(customerObj, callback) {
        $esro._private.createCustomer(customerObj, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    oboLogin: function(userName, password, callback) {
        $esro._private.oboLogin(userName, password, callback);
    },

    //-------------------------------------------------------------------------------------------------------------
    oboLogout: function(callback) {
        $esro._private.oboLogout(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getCustomerHistory: function(callback) {
        $esro._private.getCustomerHistory(callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getEventDescription: function(eventId, callback) {
        $esro._private.getEventDescription(eventId, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    reprintTransaction: function(tranId, callback) {
        $esro._private.reprintTransaction(tranId, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    setCulture: function(culture, callback) {
        $esro._private.setCulture(culture, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    //Available cachetypenames: countries, titles, cities, states, regions, genders, dataprotectionquestions,  contacttypes
    getFromCache: function(cachetypename, callback) {
    $esro._private.getFromCache(cachetypename, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getJsonFeed: function (feedName, callback) {
    $esro._private.getJsonFeed(feedName, callback);
    },
    //-------------------------------------------------------------------------------------------------------------
    getdeliverymethods: function(callback) 
    {
        $esro._private.getdeliverymethods(callback);
    },
    
    //-
    //-------------------------------------------------------------------------------------------------------------
    getservertransaction: function(transactionid, callback) 
    {
        $esro._private.getservertransaction(transactionid, callback);
    },
    
    //-------------------------------------------------------------------------------------------------------------
    joincontext: function(contexid, callback) 
    {
        $esro._private.joincontext(contexid, callback);
    },
     //-------------------------------------------------------------------------------------------------------------
    addDeliveryToBasket: function(deliveryMethod, hasAddress, useBillingAddress, DeliveryAddress, DeliveryAddress2, DeliveryAddress3, DeliveryCity, DeliveryZipCode, DeliveryState,DeliveryCountry , callback) 
    {
        $esro._private.addDeliveryToBasket(deliveryMethod, hasAddress, useBillingAddress, DeliveryAddress, DeliveryAddress2, DeliveryAddress3, DeliveryCity, DeliveryZipCode, DeliveryState, DeliveryCountry, callback);
    },
    
    
    //-------------------------------------------------------------------------------------------------------------
    GenericCallback: function(result) {
        eval(result.EvalMe);
        result.EvalMe = "";
        if (result.CustomCallback.length > 0) {
            window[result.CustomCallback](result);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------

//----------------------------              End of $esro class                      ---------------------------

//-------------------------------------------------------------------------------------------------------------
/// verifying JQuery library is available
if (typeof (jQuery) == 'undefined') {
}

jQuery(document).ready(function() {
    $esro._private.initialize();
});
//Below is the rough format of the sessionState as it is returned from the server
//{
//	clientDetails:{
//		id:"<guid>",
//		crmId:"<string>",
//		name:{first:"<string>", last:"<string>", middle:"<string>", prefix:"<string">, suffix:"<string>"},
//		cardId:"<string>",
//		title:"<string>",
//		jobTitle:"<string>",
//		gender:"<string>",
//		birthday:"<date>",
//		maritalStatus:"<string>",
//		clientTypes:[{Id:"<guid>", Name:"<string>"},...],
//		contactDetails:[{TypeName:"<string>", Value:"<string>"}, ...],
//		dataProtection:["<guid of questions which were answered: yes>",...],
//		preferences:[{Id:"<guid>", Name:"<string>"},...]
//	},
//	//basket is represented by an object with a structure similar to the TransactionSnapshot.Basket
//	basket:{
//		items[
//			{type:"ticket", TotalPrice="$10",...},
//			{type:"ticket", TotalPrice="$10",...}
//		];
//		payments:[],
//		priceModifiers:[]
//	}
//}
	
