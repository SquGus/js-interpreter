
for (var j = 1; j <= 100; j++) {
	if (j%2 == 0) {
		console.log(j);
	} else if (j === 3) {
		console.log('j == 3');
	} else {
		console.log('This prints if j != 3 || j != even.');
	}
}