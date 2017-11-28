$(function() {
	// (AJAX) RESETS PASSWORD
	$("#reset-password-form").submit(function(e) {
		e.preventDefault();
		var form = $(this);
		var resetEmail = form.find("#reset-email").val();
		form.find("#reset-password-submit").attr("disabled", true);
		
		$.post(
			'/reset_password',
			form.serialize()
		).done(function(res) {
			Materialize.toast("Email sent!", 5000, "toast-success");
			$("#reset-password").modal('close');
			form.find("input").val("");
			
		}).fail(function(data) {
			data.responseJSON.forEach(function(message) {
				Materialize.toast(message, 5000, "toast-error");
			});
			console.log(data);
		});
		form.find("#reset-password-submit").attr("disabled", false);
	});
});