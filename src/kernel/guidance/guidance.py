"""
NAME: guidance.py
PURPOSE: Contains the Guidance logic for MESA kernel to KRPC (Includes Guidance Algorithms, Guidance Calculations, and Guidance Commands)

"""

class Guidance:
    def __init__(self, vessel, conn):
        self.vessel = vessel
        self.conn = conn

    def InitLaunch(self):
        if self.vessel is not None:
            ctrl = self.vessel.control

            ctrl.sas = True
            ctrl.throttle = 1.0
            ctrl.activate_next_stage()
            self.vessel = self.conn.space_center.active_vessel
            return "System Launch Initialized: SAS Activated, Throttle Set to 100%, Next Stage Activated"
    
        else:
            print("No vessel available to initialize launch guidance.")