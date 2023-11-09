class Horas:
    def __init__(self, hora=6, minuto=0):
        self.Hora = hora
        self.Min = minuto

    def Show_Hora(self):
        print(f"{self.Hora:02d}:{self.Min:02d}")

    def SetHora(self, hora, minuto):
        self.Hora = hora
        self.Min = minuto

    def GetHora(self):
        return self

    def Get_H(self):
        return self.Hora

    def Get_M(self):
        return self.Min

    def Add_Min(self):
        self.Min += 10
        if self.Min >= 60:
            self.Hora += 1
            self.Min = 0
            if self.Hora >= 24:
                self.Hora = 0

    def __ge__(self, hora):
        return (self.Hora, self.Min) >= (hora.Get_H(), hora.Get_M())

    def __eq__(self, hora):
        return (self.Hora, self.Min) == (hora.Get_H(), hora.Get_M())
