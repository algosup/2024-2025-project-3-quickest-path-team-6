#ifndef CONVERSION_XML
#define CONVERSION_XML
#include "../Includes/includes.hpp"

void convertIntoXml(vector<int> path, int task_duration, tinyxml2::XMLDocument& xml_doc) {
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

    cout << "Request completed. Path converted into XML response.\n" << endl;
}

#endif