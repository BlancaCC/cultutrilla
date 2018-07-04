# Dash

Como dicen en su página wed dash es:
Dash is a Python framework for building analytical web applications. No JavaScript required.

## Para instalar dash
```
pip install dash==0.21.1  # The core dash backend
pip install dash-renderer==0.13.0  # The dash front-end
pip install dash-html-components==0.11.0  # HTML components
pip install dash-core-components==0.23.0  # Supercharged components
pip install plotly --upgrade  # Latest Plotly graphing library
pip install pandas   # work with csv 

```
## Básicos
### Bibliotecas báscias

```
import dash
import dash_core_components as dcc
import dash_html_components as html
```
### Clases iniciales de las bibliotecas

- Asignamos la clase a una variable ` app = dash.Dash() `

#### Capa layout
`app.layout = html.Div ( children = lista de argumentos)`

##### Argumentos en la lista

`html.H1` Cabecera
```
html.Div(children='''
        TEXTO DEBAJO DE LA CABECERA 
    ''')
```
``` python
dcc.Graph
(
	id = 'NOMBRE'
	figure =
	{
		data
	}
app.layout = html.Div(children=[
    html.H1(children='Hello Dash'),

    html.Div(children='''
        Dash: A web application framework for Python.
    '''),

    dcc.Graph(
        id='example-graph',
        figure={
            'data': [
                {'x': [1, 2, 3], 'y': [4, 1, 2], 'type': 'bar', 'name': 'SF'},
                {'x': [1, 2, 3], 'y': [2, 4, 5], 'type': 'bar', 'name': u'Montréal'},
            ],
            'layout': {
                'title': 'Dash Data Visualization'
            }
        }
    )
])
```
## Colores y otras cosillas
```
colors = {
    'background': '#111111',
    'text': '#7FDBFF'
}

```

## Tipografía
`app.css.append_css({"external_url": "https://codepen.io/chriddyp/pen/bWLwgP.css"}) `

Para mejores fuentes: https://dash.plot.ly/external-resources

## Para ejecutar
```python
if __name__ == '__main__':
    app.run_server(debug=True)

```

### Dash core components
import from libray
`import dash_core_components as dcc`

#### Dropdown

Pestañas que bajan
` import dash_core_components as dcc `
Ejemplo de código
```

dcc.Dropdown(
    options=[
        {'label': 'New York City', 'value': 'NYC'},
        {'label': 'Montréal', 'value': 'MTL'},
        {'label': 'San Francisco', 'value': 'SF'}
    ],
    value='MTL'
)
```
#### slider
Para hacer barras que se mueven  
