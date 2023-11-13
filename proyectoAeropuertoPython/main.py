import streamlit as st
import pandas as pd
from datetime import date
from controler import Controller


def main():
    df = pd.DataFrame({
        'first column': [1, 2, 3, 4],
        'second column': [10, 20, 30, 40]
        })

    option = st.selectbox(
        'Which number do you like best?',
        df['first column'])

    'You selected: ', option

    date = st.date_input("Pick a date")
    controler = Controller()
    controler.Show_Menu()

main()


