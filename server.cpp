#include <crow.h>
#include <iostream>
#include "config.h"

int main()
{ 
    crow::SimpleApp app;
    CROW_ROUTE(app, "/hello")([](){
        // Simple get request and string responce
        return "world";
    });

    CROW_ROUTE(app, "/json_get")([](){
        // Simple get request and JSON resp
        crow::json::wvalue json_resp;
        json_resp["status"] = true;
        json_resp["info"] = "Information";
        return json_resp;
    });

    CROW_ROUTE(app, "/html")([](){
        // Simple get request and responce as html
        auto page = crow::mustache::load("test.html");
        return page.render();
    });
    app.port(PORT).run_async(); // run async server
}