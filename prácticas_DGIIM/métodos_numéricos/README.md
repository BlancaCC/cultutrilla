# Máxima solución de problemas  
	Tras instalar maxima y wxmaxima o bien desde la [wed](http://maxima.sourceforge.net/download.html), desde el centro de software de tu distribución o desde la terminal (`sudo apt-get install maxima wxmaxima`), con algunas funciones como `matriz_size()` me aparecía el siguiente mensaje de error: `file_search1: <algo> not found in file_search_maxima,file_search_lisp.` 
	La forma de solucionarlo es tener instalado texinfo y maxima-share:  
		`sudo apt-get install texinfo maxima-share `
