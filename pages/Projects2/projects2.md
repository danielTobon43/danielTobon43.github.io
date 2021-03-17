---
layout: page
title: Projects
subtitle: 
<!-- js: "/js/projects.js" -->
<!-- css: "/assets/css/projects.css" -->
---




  <p>Before the script...</p>
  <div id="container">
    <div id="output">NO DATA 2</div>
  </div>

  <!-- <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script> -->


  <script>
    var url = "http://danieltobon43.pythonanywhere.com/projects";

    // $.ajax({
    //   method: "GET",
    //   cache: false,
    //   url: url,
    //   success: function(data) {
    //     document.getElementById('output').innerHTML = data.total;
    //   },
    //   error: function(error) {
    //     //What do you want to do with the error?
    //     document.getElementById('output').innerHTML = "something wrong!";
    //   },
    // });

    function CallURL()  {
    $.ajax({
        url: url
        type: "GET",
        dataType: "jsonp",
        async: false,
        success: function(msg)  {
            JsonpCallback(msg);
        },
        error: function()  {
            ErrorFunction();
        }
    });
}

function JsonpCallback(json)  {
    document.getElementById('output').innerHTML = json.result;
}

</script>

  <p>...After the script.</p>

