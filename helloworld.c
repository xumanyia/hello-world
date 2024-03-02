name: 'Baidu Tieba Auto Sign'

on:
  push:
    branches:
      - main
  schedule:
    - cron: '5 16,22 * * *'

jobs:
  tieba_sign:
    runs-on: ubuntu-latest
    steps:
      - name: 'Checkout codes'
        uses: actions/checkout@v2
      - name: 'Set python'
        uses: actions/setup-python@v1
        with:
          python-version: '3.6'
      - name: 'Install dependencies'
        run: python -m pip install --upgrade requests
      - name: 'Start Sign'
        env:
          BDUSS: ${{ secrets.BDUSS }}
          HOST: ${{ secrets.HOST }}
          FROM: ${{ secrets.FROM }}
          TO: ${{ secrets.TO }}
          AUTH: ${{ secrets.AUTH }}
        run: python main.py
