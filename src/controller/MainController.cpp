// #include "MainController.h"
// #include "../SD/SD_Utils.h"

// void MainController::handleRequest(AsyncWebServerRequest *request) {
//   String path = request->url();
  
//   if (path.endsWith("/")) {
//     path += "index.html";
//   }
  
//   if (SD_Utils::fileExists(path.c_str())) {
//     String content = SD_Utils::getFileContent(path.c_str());
//     request->send(200, "text/html", content);
//   }
//   else {
//     request->send(404);
//   }
// }


// // void handleNotFound(){
// //   String message = "File Not Found\n\n";
// //   message += "URI: ";
// //   message += server.uri();
// //   message += "\nMethod: ";
// //   message += (server.method() == HTTP_GET)?"GET":"POST";
// //   message += "\nArguments: ";
// //   message += server.args();
// //   message += "\n";
// //   for (uint8_t i = 0; i < server.args(); i++){
// //     message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
// //   }
// //   server.send(404, "text/plain", message);
// // }