---
layout: page
title: Projects
subtitle: 
js: "/js/projects.js"
css: "/assets/css/projects.css"
---

<!DOCTYPE HTML>
<html>

<body>


  <p>Before the script...</p>
  <div id="container">
    <div id="output">NO DATA</div>
  </div>

  <!-- <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script> -->
  

  <script>
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

</script>

  <p>...After the script.</p>

</body>

</html>