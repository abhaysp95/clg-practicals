function validateEmail(inputText) {
	let mailformat = /^w+([.-]?w+)*@w+([.-]?w+)*(.w{2,3})+$/;
	if (inputText.value.match(mailformat)) {
		alert("You have entered email in right way");
		document.form1.text1.focus();
		return true;
	}
	else {
		alert("You have not entered corret type of email");
		document.form1.text1.focus();
		return false;
	}
}
