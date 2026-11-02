#!/usr/bin/env python3
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
from plotly.subplots import make_subplots

df = pd.read_csv('/mnt/dev/tita_ws/src/力矩_位置_速度实时数据.csv')

fig = make_subplots(rows=3, cols=1, subplot_titles=('Effort', 'Position', 'Velocity'))

for i in range(8):
    fig.add_trace(go.Scatter(x=df['Time(s)'], y=df[f'Joint{i+1}_Effort(Nm)'],
                             name=f'J{i+1}', mode='lines'), row=1, col=1)
    fig.add_trace(go.Scatter(x=df['Time(s)'], y=df[f'Joint{i+1}_Position(rad)'],
                             name=f'J{i+1}', mode='lines', showlegend=False), row=2, col=1)
    fig.add_trace(go.Scatter(x=df['Time(s)'], y=df[f'Joint{i+1}_Velocity(rad/s)'],
                             name=f'J{i+1}', mode='lines', showlegend=False), row=3, col=1)

fig.update_layout(height=900, title_text="Joint Control Data")
fig.write_html("/mnt/dev/tita_ws/src/力矩_位置_速度图表.html")
print("HTML saved to /mnt/dev/tita_ws/src/力矩_位置_速度图表.html")