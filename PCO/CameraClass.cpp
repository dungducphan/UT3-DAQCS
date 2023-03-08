/*----- PROTECTED REGION ID(CameraClass.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        CameraClass.cpp
//
// description : C++ source for the CameraClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the Camera once per process.
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


#include <CameraClass.h>

/*----- PROTECTED REGION END -----*/	//	CameraClass.cpp

//-------------------------------------------------------------------
/**
 *	Create CameraClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Camera_class(const char *name) {
		return Camera_ns::CameraClass::init(name);
	}
}

namespace Camera_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
CameraClass *CameraClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		CameraClass::CameraClass(string &s)
 * description : 	constructor for the CameraClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
CameraClass::CameraClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering CameraClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(CameraClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::constructor

	cout2 << "Leaving CameraClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		CameraClass::~CameraClass()
 * description : 	destructor for the CameraClass
 */
//--------------------------------------------------------
CameraClass::~CameraClass()
{
	/*----- PROTECTED REGION ID(CameraClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		CameraClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
CameraClass *CameraClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new CameraClass(s);
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
 * method : 		CameraClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
CameraClass *CameraClass::instance()
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
	((static_cast<Camera *>(device))->grab_image());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : CameraClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum CameraClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : CameraClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum CameraClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : CameraClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum CameraClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : CameraClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void CameraClass::set_default_property()
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
 *	Method      : CameraClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void CameraClass::write_class_property()
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
 *	Method      : CameraClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void CameraClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(CameraClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Camera(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Camera *dev = static_cast<Camera *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(CameraClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : CameraClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void CameraClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(CameraClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::attribute_factory_before
	//	Attribute : exposureTime
	exposureTimeAttrib	*exposuretime = new exposureTimeAttrib();
	Tango::UserDefaultAttrProp	exposuretime_prop;
	exposuretime_prop.set_description("Exposure Time in nanoseconds.");
	exposuretime_prop.set_label("Exposure Time");
	exposuretime_prop.set_unit("ns");
	//	standard_unit	not set for exposureTime
	//	display_unit	not set for exposureTime
	//	format	not set for exposureTime
	exposuretime_prop.set_max_value("10000000000");
	exposuretime_prop.set_min_value("10");
	//	max_alarm	not set for exposureTime
	//	min_alarm	not set for exposureTime
	//	max_warning	not set for exposureTime
	//	min_warning	not set for exposureTime
	//	delta_t	not set for exposureTime
	//	delta_val	not set for exposureTime
	
	exposuretime->set_default_properties(exposuretime_prop);
	//	Not Polled
	exposuretime->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(exposuretime);

	//	Attribute : frameRate
	frameRateAttrib	*framerate = new frameRateAttrib();
	Tango::UserDefaultAttrProp	framerate_prop;
	//	description	not set for frameRate
	framerate_prop.set_label("Frame Rate");
	framerate_prop.set_unit("Hz");
	//	standard_unit	not set for frameRate
	//	display_unit	not set for frameRate
	//	format	not set for frameRate
	//	max_value	not set for frameRate
	//	min_value	not set for frameRate
	//	max_alarm	not set for frameRate
	//	min_alarm	not set for frameRate
	//	max_warning	not set for frameRate
	//	min_warning	not set for frameRate
	//	delta_t	not set for frameRate
	//	delta_val	not set for frameRate
	
	framerate->set_default_properties(framerate_prop);
	//	Not Polled
	framerate->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(framerate);

	//	Attribute : triggerMode
	triggerModeAttrib	*triggermode = new triggerModeAttrib();
	Tango::UserDefaultAttrProp	triggermode_prop;
	//	description	not set for triggerMode
	triggermode_prop.set_label("Trigger Mode");
	//	unit	not set for triggerMode
	//	standard_unit	not set for triggerMode
	//	display_unit	not set for triggerMode
	//	format	not set for triggerMode
	//	max_value	not set for triggerMode
	//	min_value	not set for triggerMode
	//	max_alarm	not set for triggerMode
	//	min_alarm	not set for triggerMode
	//	max_warning	not set for triggerMode
	//	min_warning	not set for triggerMode
	//	delta_t	not set for triggerMode
	//	delta_val	not set for triggerMode
	
	triggermode->set_default_properties(triggermode_prop);
	//	Not Polled
	triggermode->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(triggermode);

	//	Attribute : beamProfileImg
	beamProfileImgAttrib	*beamprofileimg = new beamProfileImgAttrib();
	Tango::UserDefaultAttrProp	beamprofileimg_prop;
	//	description	not set for beamProfileImg
	beamprofileimg_prop.set_label("Beam Profile Image");
	//	unit	not set for beamProfileImg
	//	standard_unit	not set for beamProfileImg
	//	display_unit	not set for beamProfileImg
	//	format	not set for beamProfileImg
	//	max_value	not set for beamProfileImg
	//	min_value	not set for beamProfileImg
	//	max_alarm	not set for beamProfileImg
	//	min_alarm	not set for beamProfileImg
	//	max_warning	not set for beamProfileImg
	//	min_warning	not set for beamProfileImg
	//	delta_t	not set for beamProfileImg
	//	delta_val	not set for beamProfileImg
	
	beamprofileimg->set_default_properties(beamprofileimg_prop);
	//	Not Polled
	beamprofileimg->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(beamprofileimg);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(CameraClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : CameraClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void CameraClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(CameraClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::pipe_factory_before
	/*----- PROTECTED REGION ID(CameraClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : CameraClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void CameraClass::command_factory()
{
	/*----- PROTECTED REGION ID(CameraClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::command_factory_before


	//	Command GrabImage
	GrabImageClass	*pGrabImageCmd =
		new GrabImageClass("GrabImage",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pGrabImageCmd);

	/*----- PROTECTED REGION ID(CameraClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		CameraClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void CameraClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(CameraClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		CameraClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void CameraClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Camera *dev = static_cast<Camera *> (dev_impl);

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
	/*----- PROTECTED REGION ID(CameraClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	CameraClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : CameraClass::get_attr_object_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *CameraClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(CameraClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	CameraClass::Additional Methods
} //	namespace
