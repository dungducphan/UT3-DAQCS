/*----- PROTECTED REGION ID(DeviceAClass.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        DeviceAClass.cpp
//
// description : C++ source for the DeviceAClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the DeviceA once per process.
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <DeviceAClass.h>

/*----- PROTECTED REGION END -----*/	//	DeviceAClass.cpp

//-------------------------------------------------------------------
/**
 *	Create DeviceAClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_DeviceA_class(const char *name) {
		return DeviceA_ns::DeviceAClass::init(name);
	}
}

namespace DeviceA_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
DeviceAClass *DeviceAClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		DeviceAClass::DeviceAClass(string &s)
 * description : 	constructor for the DeviceAClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
DeviceAClass::DeviceAClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering DeviceAClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(DeviceAClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::constructor

	cout2 << "Leaving DeviceAClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		DeviceAClass::~DeviceAClass()
 * description : 	destructor for the DeviceAClass
 */
//--------------------------------------------------------
DeviceAClass::~DeviceAClass()
{
	/*----- PROTECTED REGION ID(DeviceAClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		DeviceAClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
DeviceAClass *DeviceAClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new DeviceAClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		DeviceAClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
DeviceAClass *DeviceAClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		GrabImageClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *GrabImageClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "GrabImageClass::execute(): arrived" << endl;
	((static_cast<DeviceA *>(device))->grab_image());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum DeviceAClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum DeviceAClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum DeviceAClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void DeviceAClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
}

//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void DeviceAClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void DeviceAClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(DeviceAClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new DeviceA(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		DeviceA *dev = static_cast<DeviceA *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(DeviceAClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void DeviceAClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(DeviceAClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::attribute_factory_before
	//	Attribute : TestAttribute_A1
	TestAttribute_A1Attrib	*testattribute_a1 = new TestAttribute_A1Attrib();
	Tango::UserDefaultAttrProp	testattribute_a1_prop;
	//	description	not set for TestAttribute_A1
	//	label	not set for TestAttribute_A1
	//	unit	not set for TestAttribute_A1
	//	standard_unit	not set for TestAttribute_A1
	//	display_unit	not set for TestAttribute_A1
	//	format	not set for TestAttribute_A1
	//	max_value	not set for TestAttribute_A1
	//	min_value	not set for TestAttribute_A1
	//	max_alarm	not set for TestAttribute_A1
	//	min_alarm	not set for TestAttribute_A1
	//	max_warning	not set for TestAttribute_A1
	//	min_warning	not set for TestAttribute_A1
	//	delta_t	not set for TestAttribute_A1
	//	delta_val	not set for TestAttribute_A1
	
	testattribute_a1->set_default_properties(testattribute_a1_prop);
	//	Not Polled
	testattribute_a1->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(testattribute_a1);

	//	Attribute : TestAttribute_A2
	TestAttribute_A2Attrib	*testattribute_a2 = new TestAttribute_A2Attrib();
	Tango::UserDefaultAttrProp	testattribute_a2_prop;
	//	description	not set for TestAttribute_A2
	//	label	not set for TestAttribute_A2
	//	unit	not set for TestAttribute_A2
	//	standard_unit	not set for TestAttribute_A2
	//	display_unit	not set for TestAttribute_A2
	//	format	not set for TestAttribute_A2
	//	max_value	not set for TestAttribute_A2
	//	min_value	not set for TestAttribute_A2
	//	max_alarm	not set for TestAttribute_A2
	//	min_alarm	not set for TestAttribute_A2
	//	max_warning	not set for TestAttribute_A2
	//	min_warning	not set for TestAttribute_A2
	//	delta_t	not set for TestAttribute_A2
	//	delta_val	not set for TestAttribute_A2
	
	testattribute_a2->set_default_properties(testattribute_a2_prop);
	//	Not Polled
	testattribute_a2->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(testattribute_a2);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(DeviceAClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void DeviceAClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(DeviceAClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::pipe_factory_before
	/*----- PROTECTED REGION ID(DeviceAClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void DeviceAClass::command_factory()
{
	/*----- PROTECTED REGION ID(DeviceAClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::command_factory_before


	//	Command GrabImage
	GrabImageClass	*pGrabImageCmd =
		new GrabImageClass("GrabImage",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pGrabImageCmd);

	/*----- PROTECTED REGION ID(DeviceAClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		DeviceAClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void DeviceAClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(DeviceAClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		DeviceAClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void DeviceAClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		DeviceA *dev = static_cast<DeviceA *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(DeviceAClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DeviceAClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : DeviceAClass::get_attr_object_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *DeviceAClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(DeviceAClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	DeviceAClass::Additional Methods
} //	namespace