#include <iostream>
#include <vector>
#include "../../Libraries/Tinyxml2/tinyxml2.h"

using namespace std;

void convertIntoXml(vector<int> path, int task_duration) {
    // Create an XML document
    tinyxml2::XMLDocument xml_doc;

    // Add a root element
    tinyxml2::XMLElement* root = xml_doc.NewElement("Path");
    xml_doc.InsertFirstChild(root);

    // Add vector elements to the XML
    for (int value : path) {
        tinyxml2::XMLElement* item = xml_doc.NewElement("Landmark");
        item->SetText(value);
        root->InsertEndChild(item);
    }

    tinyxml2::XMLElement* item = xml_doc.NewElement("Time");
    item->SetText(task_duration);
    root->InsertEndChild(item);

    // Save the XML to a file
    if (xml_doc.SaveFile("../Client/Bin/pathQuick.xml") == tinyxml2::XML_SUCCESS) {
        cout << "Path converted into XML, data written to pathQuick.xml\n" << endl;
    } else {
        cerr << "Error writing XML data to file." << endl;
    }
}
