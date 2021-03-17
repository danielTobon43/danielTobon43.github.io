---
layout: page
title: Projects
subtitle: 
js: "/js/main.js"
---

<div class="btn-group" style="padding-bottom:3px;">
  <a href="#" id="prev" class="btn">Previous Day</a>
  <a href="#" id="next" class="btn">Next Day</a>                
</div>
<div id="displayResults" name="displayResults"></div>

<script type="text/javascript">
$("#next, #prev").click(function(e){
    e.preventDefault();
    $.ajax({
        url: 'http://danieltobon43.pythonanywhere.com/projects',

        // data: date,
        // type: 'GET',
        // success: function (data) {
        //     $('#displayResults').html(data);
        // }
    });

    .done(function( data ) {
      data.forEach((repo) => {
        var center = $("#" + repo.name + " > center");
        if (center.length) {
          center.find("div > .stars").text(repo.stargazers_count);
          center.find("a.repo-description").text(repo.description.replace(/:[^ :]+: ?/, ""));
          center.find("a").attr("href", repo.html_url);
        }
      })
      console.info(data);
      $('#displayResults').html(data)
      hah = data;
    });
});
</script>