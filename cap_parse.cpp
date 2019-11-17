/*
Author: Courtland Crouchet
*/
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
using namespace rapidxml;
using namespace std;

void cap_parse()
{

	xml_document<> doc;
	xml_node<> * root_node;
	xml_node<> * info_node;
	xml_node<> * body_node;
	//Read the xml file into a vector
	ifstream capFile ("CAP.xml");
	vector<char> buffer((istreambuf_iterator<char>(capFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	//Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	//Find root node
	root_node = doc.first_node("alert");
	info_node = root_node->first_node("info");

	body_node = info_node->first_node("headline");
	if(body_node != 0) cout << body_node->value() << "\n\n";

	body_node = info_node->first_node("description");
	if(body_node != 0) cout << body_node->value() << "\n\n";

	body_node = info_node->first_node("instruction");
	if(body_node != 0) cout << body_node->value() << "\n";
	// std::cout << "Flu's goin round";
}
