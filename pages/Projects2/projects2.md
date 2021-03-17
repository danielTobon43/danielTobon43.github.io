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
  <div id="output">NO DATA 3</div>
  <div id="output2">NO DATA 1</div>
</div>

<script>
  var url = "http://danieltobon43.pythonanywhere.com/projects";

$.ajax({
  method: "GET",
  cache: false,
  url: url,
  success: function(data) {
    // document.getElementById('output').innerHTML = data.total;
    document.getElementById('output').innerHTML = "rico";
  },
  error: function(error) {
    //What do you want to do with the error?
    document.getElementById('output2').innerHTML = "error nene";
  },
});
  
</script>

