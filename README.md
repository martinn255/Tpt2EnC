Propuesta 1 : (Delta como Lista de Transiciones) Es mas facil y directa de implementar ya que tiene a delta que recorre la lista de transiciones con (Automata(destino),q,a), es facil de debuggear ya que es igual a su definicion, pero cuando un automata es grande es donde tiene mas problemas ya que se tiene que ingresar cada transicion.

Propuesta 2 — Delta Indexado por Estado
Cada estado posee su transiciones por lo que se puede visualizar como un grafo lo que le hace facil de interpretar y acceder, sobre todo es practico para AFNDs ya que posee el conjunto de estados destinos.

Propuesta 3 — Delta como Matriz Dispersa
Tiene la representacion de delta como una matriz donde cada estado se guarda como una fila y cada simbolo como una columna lo que hace que busqueda de delta(q, a) sea mas directa y eficiente (acceso O(1)), aunque a simple vista para transformar un AFND a AFD puede tener su complejidad.

Propuesta 4:(Delta Funcional)la idea es representar en delta cada transicion y obtener los nuevos estados (busca el estado y Simbolo o Alfabeto) es excelente en la representacion matematica y para AFND y su mayor ventaja es su razonamiento formal 

Propuesta 5:(Estado compuesto para Determinazion) La idea general es que cada determinacion de cada estado del AFD es un subconjunto de estados AFND esto nos da una representacion mas general del Automata con la teoria formal.No sirve para utilizar ya que depende de la representacion del AFND y de cada cambio nuevo.

Nuestro grupo después de debatir llegamos a que la propuesta que vamos a elegir es la cuarta propuesta ya que sirve para AFND y AFD es mas fácil su entrada ya que es mas natural a como se modela un AF también no necesitas conocer cuantos estados hay, otra ventaje es la flexibilidad al momento de eliminar o modificar transiciones y la simulación de cadenas pero eso si a la hora la ejecución hay que buscar cada uno y es lo mas difícil.

