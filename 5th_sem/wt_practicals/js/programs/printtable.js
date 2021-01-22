function printDiv(divId) {
	// get the div html
	var divElements = document.getElementById(divId).innerHTML;
	// get the HTML of whole page
	var oldPage = document.body.innerHTML;
	// reset the page's HTML with div's HTML only
	document.body.innerHTML = "<html><head><title></title></head><body>" + divElements + "</body>";
	// print page
	window.print();
	// restore orignal HTML
	document.body.innerHTML = oldPage;
}
