import krpc


"""
    Name: conn.py
    Purpose: Contains the Connection logic for MESA kernel to KRPC (Includes Establishing, Closing, Retrying, and Executing commands)
"""
class Connection:
    def __init__(self, conn):
        self.conn = conn

    def Establish(self):
        try:
            self.conn = krpc.connect(name='MESA Kernel', rpc_port=6000, stream_port=6001)
        except Exception as e:
            print(f"Failed to establish connection: {e}")
            self.conn = None

    def Close(self):
        if(self.conn is not None):
            self.conn.close()
            self.conn = None
        else:
            print("No connection to close.")

    def Retry(self, max_retries : int = 3):
        retries = 0
        while retries < max_retries:
            try:
                self.Establish()
                if self.conn is not None:
                    print("Connection established successfully.")
                    return
            except Exception as e:
                print(f"Retry {retries + 1}/{max_retries} failed: {e}")
            retries += 1
        print("Max retries reached. Could not establish connection.")

# -- Runs a Command sent from MESA Kernel to KRPC, and returns the result of the command execution
    def GetVessel(self, name : str = None):
        if self.conn is not None:
            try:
                vessels = self.conn.space_center.vessels
                if name is not None:
                    vessel = [v for v in vessels if v.name == name]
                    print(vessel[0].name)
                return vessel
            except Exception as e:
                print(f"Failed to get vessel: {e}")
                return None
        else:
            print("No connection available to get vessel.")
            return None