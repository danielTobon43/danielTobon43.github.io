---
layout: page
title: Projects
subtitle: 
<!-- js: "/js/main.js" -->
css: "/assets/css/projects.css"
---

<div class="btn-group" style="padding-bottom:3px;">
  <a href="#" id="prev" class="btn">Previous Day</a>
  <a href="#" id="next" class="btn">Next Day</a>                
</div>
<div id="displayResults" name="displayResults"></div>

<script type="text/javascript">
$("#next, #prev").click(

  // function(e){
  //   e.preventDefault();
  //   $.ajax({
  //       url: 'http://danieltobon43.pythonanywhere.com/projects',

  //       // data: 'projects',
  //       type: 'GET',
  //       success: function (data) {
  //           $('#displayResults').html(data);
  //       }
  //   });

  // }
  function parseURLParams(url) {
    var queryStart = url.indexOf("?") + 1,
        queryEnd   = url.indexOf("#") + 1 || url.length + 1,
        query = url.slice(queryStart, queryEnd - 1),
        pairs = query.replace(/\+/g, " ").split("&"),
        parms = {}, i, n, v, nv;

    if (query === url || query === "") return;

    for (i = 0; i < pairs.length; i++) {
        nv = pairs[i].split("=", 2);
        n = decodeURIComponent(nv[0]);
        v = decodeURIComponent(nv[1]);

        if (!parms.hasOwnProperty(n)) parms[n] = [];
        parms[n].push(nv.length === 2 ? v : null);
    }
    return parms;
  }

);
</script>