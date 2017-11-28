for (var i = 1; i <= 100; i++) {
	if (i%2 == 0) {
		console.log(i);
	} else if (i === 3) {
		console.log('i == 3');
	} else {
		console.log('This prints if i != 3 || i != even.');
	}
}