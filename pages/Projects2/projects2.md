---
layout: page
title: Projects
subtitle: 
<!-- js: "/js/projects.js" -->
<!-- css: "/assets/css/projects.css" -->
---

<p>Before the script...</p>


<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script>

<div id="container">
  <div id="output">NO DATA 1</div>
  <div id="output2">NO DATA 2</div>
</div>

<script>
  var url = "https://danieltobon43.pythonanywhere.com/projects";
  // var url = "https://sourceforge.net/projects/kaais/files/stats/json?start_date=2013-08-18&end_date=2018-04-19";


$.ajax({
  method: "GET",
  cache: false,
  url: url,
  success: function(data) {
    // document.getElementById('output').innerHTML = data.total;
    // document.getElementById('output').innerHTML = "rico";
    document.getElementById('output').innerHTML = data;
  },
  error: function(error) {
    //What do you want to do with the error?
    document.getElementById('output2').innerHTML = "error nene";
  },
});
  
</script>

