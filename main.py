import streamlit as st
import pandas as pd
from datetime import date
from controler import Controller


def main():
    controler = Controller()
    controler.Show_Menu()

main()


