var url = "http://danieltobon43.pythonanywhere.com/projects";

$.ajax({
  method: "GET",
  cache: false,
  url: url,
  success: function(data) {
    document.getElementById('output').innerHTML = data.total;
  },
  error: function(error) {
    //What do you want to do with the error?
  },
});
