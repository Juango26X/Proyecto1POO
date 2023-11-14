class Fecha:
    def __init__(self, dia=9, mes=10, agno=2023):
        self.Dia = dia
        self.Mes = mes
        self.Agno = agno

    def getDia(self):
        return self.Dia

    def getMes(self):
        return self.Mes

    def getAgno(self):
        return self.Agno

    def setDia(self, dia):
        self.Dia = dia

    def setMes(self, mes):
        self.Mes = mes

    def setAgno(self, agno):
        self.Agno = agno

    def Get_Fecha(self):
        return self

    def __eq__(self, fecha):
        return (self.Dia == fecha.getDia()) and (self.Mes == fecha.getMes()) and (self.Agno == fecha.getAgno())

    def Show_Fecha(self):
        print(f"{self.Dia}/{self.Mes}/{self.Agno}")

    def AddDia(self):
        self.Dia += 1
        if self.Dia >= 31:
            self.Dia = 1
            self.Mes += 1
        if self.Mes >= 12 and self.Dia >= 31:
            self.Mes = 1
            self.Dia = 1
            self.Agno += 1
