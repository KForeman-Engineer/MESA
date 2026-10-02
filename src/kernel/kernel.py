from interface.connection.conn import Connection
from guidance.guidance import Guidance


class Kernel:
    def __init__(self):
        self.conn = Connection(None)
        self.guidance = None
        self.vessel = None

    def Connect(self):
        self.conn.Establish()
        if self.conn.conn is not None:
            print("Connection to KRPC established.")
            self.vessel = self.conn.GetVessel("MESA1")
            if self.vessel is not None:
                print(f"Active vessel: {self.vessel[0].name}")
                self.guidance = Guidance(self.vessel[0], self.conn.conn)
            else:
                print("No active vessel found.")
        else:
            print("Failed to establish connection to KRPC.")

    def Laucnh(self):
        if self.guidance is not None:
            result = self.guidance.InitLaunch()
            print(result)
        else:
            print("Guidance system not initialized. Cannot launch.")
    def Disconnect(self):
        self.conn.Close()


KernelInstance = Kernel()
KernelInstance.Connect()
KernelInstance.Laucnh()