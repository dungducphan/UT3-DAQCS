/*
 * Example of a client using the TANGO C++ api.
 */
#include <tango.h>

using namespace Tango;

int main(int argc, char **argv) {
    try {

        //
        // create a connection to a TANGO device
        //

        DeviceProxy *device = new DeviceProxy("ms/devA/a0");

        //
        // Ping the device
        //

        device->ping();

        //
        // Execute a command on the device and extract the reply as a string
        //

        string db_info;
        DeviceData cmd_reply;
        for (unsigned i = 0; i < 1000; i++) cmd_reply = device->command_inout("GrabImage");
        // cout << "Command reply " << cmd_reply << endl;

        //
        // Read a device attribute (string data type)
        //

//        string spr;
//        DeviceAttribute att_reply;
//        att_reply = device->read_attribute("TestAttribute_A1");
//        att_reply >> spr;
//        cout << "Database device stored procedure release: " << spr << endl;
    } catch (DevFailed &e) {
        Except::print_exception(e);
        exit(-1);
    }
}