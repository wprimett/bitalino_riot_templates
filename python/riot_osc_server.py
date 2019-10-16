"""Small example OSC server adapted from https://pypi.org/project/python-osc/
    
    This program listens to addresses with the address /<id>/raw where id is an integer
    If the connection is successful, incoming data will be printed in the console
    
    Default aguments assume the standard network configuration of the R-IoT module out-of-the-box. If these have been change, please alter the arguments accordingly
    """
import argparse
import math

from pythonosc import dispatcher
from pythonosc import osc_server

labels = ["ACC_X", "ACC_Y", "ACC_Z", "GYRO_X", "GYRO_Y", "GYRO_Z", "MAG_X", "MAG_Y", "MAG_Z","TEMP", "IO", "A1", "A2", "C", "Q1", "Q2", "Q3", "Q4", "PITCH", "YAW", "ROLL", "HEAD"]

## Data arrives to this function as a sinlge tuple argument
## This contains 22 floats values
def riot_handler(addr, *data):
    str_output = ""
    for i, lbl in enumerate(labels):
        str_output += "%s: %f," % (lbl, data[i])
        print(str_output[:-1])
        print("")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--ip",
        default="192.168.1.100", help="The ip to listen on")
    parser.add_argument("--port",
        type=int, default=8888, help="The port to listen on")
    args = parser.parse_args()
            
    dispatcher = dispatcher.Dispatcher()
    dispatcher.map("/*/raw", riot_handler)
                
    server = osc_server.ThreadingOSCUDPServer((args.ip, args.port), dispatcher)
    print("Serving on {}".format(server.server_address))
    server.serve_forever()
