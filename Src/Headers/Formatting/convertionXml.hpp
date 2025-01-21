#include <iostream>
#include <vector>
#include "../../Libraries/Tinyxml2/tinyxml2.h"

using namespace std;

void convertIntoXml(vector<int> path, int taskDuration) {
    // Create an XML document
    tinyxml2::XMLDocument xmlDoc;

    // Add a root element
    tinyxml2::XMLElement* root = xmlDoc.NewElement("Path");
    xmlDoc.InsertFirstChild(root);

    // Add vector elements to the XML
    for (int value : path) {
        tinyxml2::XMLElement* item = xmlDoc.NewElement("Landmark");
        item->SetText(value);
        root->InsertEndChild(item);
    }

    tinyxml2::XMLElement* item = xmlDoc.NewElement("Time");
    item->SetText(taskDuration);
    root->InsertEndChild(item);

    // Save the XML to a file
    if (xmlDoc.SaveFile("Bin/pathQuick.xml") == tinyxml2::XML_SUCCESS) {
        cout << "Path converted into XML, data written to pathQuick.xml\n" << endl;
    } else {
        cerr << "Error writing XML data to file." << endl;
    }
}
