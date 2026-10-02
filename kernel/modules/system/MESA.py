

"""
    Source File for the MESA Guidance system (MGS) 
    Handles the following:

        - Connection to KRPC 
        - Initalization of Modules
        - Finding Plugins, etc
    
    File ID: SYSTEM
"""
import krpc

class MESA:
    def __init__(self):
        self.modules = None
        self.conn = None
        self.active = None

    # -- Establishes Connection to KRPC
    def Establish(self, connect_id, host_port, stream_port):
        try:
            self.conn = krpc.connect(connect_id, host_port, stream_port)
        except Exception as e:
            print("MESA: Connection Error!")
    # -- Grabs Modules
    def FetchModules(self):
        return NotImplemented

    # -- Attempts to fetch all Vessels from the Game returns a list to select from
    def FetchVessels(self):
        rockets = []
        try:
            vessels = self.conn.space_center.vessels
            for vessel in vessels:
                rockets.append(vessel.name)
            return rockets
        except Exception as e:
            print("MESA: No Valid Rocket is Active or Detectable")


    # -- Starts the Launch sequence for the Vessel
    def Launch(self, vessel):
        if self.active is not None:
            ctrl = self.active.control
            ctrl.sas = True
            ctrl.throttle = 1.0
            ctrl.activate_next_stage()
            self.active = vessel
            return "System Launch Initialized: SAS Activated, Throttle Set to 100%, Next Stage Activated"

