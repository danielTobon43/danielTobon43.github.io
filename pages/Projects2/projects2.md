---
layout: page
title: Projects
subtitle: 
<!-- js: "/js/projects.js" -->
css: "/assets/css/projects.css"
---

<p>Before the script...</p>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script>

<div id="container">
  <div id="output">NO DATA 113</div>
  <div id="output2">NO DATA 4</div>
</div>

<script>
   
  function tableCreate(table_id,rows,cols){
    var body = document.body;
    tbl = document.createElement(table_id);
    tbl.style.width = '100%';
    tbl.setAttribute('border', '0');    
    tbl.setAttribute('margin', '0'); 
    tbl.setAttribute("style", "background-color: #111111;");   
    for(var i = 0; i < rows; i++){
        var tr = tbl.insertRow();           
        for(var j = 0; j < cols; j++){            
            if(i == rows){   
            var td = tr.insertCell();               
                break;                
                
            } else {            
                var td = tr.insertCell();
                if(i == rows ){
                    td.setAttribute('rowSpan', '2');                                
                }
            }            
        }       
        
    }    
    return tbl;
}
  
</script>


<script>

  function tableFillData(){
    var url = "https://danieltobon43.pythonanywhere.com/projects";     

    $.ajax({
      method: "GET",
      cache: false,
      url: url,
      dataType: "json",
      success: function(data) {

        var key, rows = 0;
        for(key in data.projects) {
          if(data.projects.hasOwnProperty(key)) {
            rows++;
          }
        }
        
        console.log(rows);     
        data = JSON.stringify([data.projects]);    
        data = JSON.parse(data);
        
        table = tableCreate("table",1,rows);
        
        var row = 0;
        var col = 0;    
        data.forEach(obj => {
          Object.entries(obj).forEach(([key, value]) => {
                      
            if (col == 0){
            
              var div = document.createElement("div");    
              var td = table.rows[row].cells[0];
              var img = document.createElement("img");             
              img.src = value.images;
              img.width = 240
              img.height = 100
              img.onclick = function() {
                window.location.href = value.url;
              }
              td.appendChild(document.createTextNode(value.name)); 
              var br = document.createElement("br");
              td.appendChild(br);
              td.appendChild(img);              
              td.appendChild(document.createTextNode(value.description));                           
              col++;
            
            
            }else{
              var div = document.createElement("div");   
              var td = table.rows[row].cells[1];
              var img = document.createElement("img");
              img.src = value.images;
              img.width = 240
              img.height = 100
              img.onclick = function() {
                window.location.href = value.url;
              }
              td.appendChild(document.createTextNode(value.name)); 
              var br = document.createElement("br");
              td.appendChild(br);
              td.appendChild(img);              
              td.appendChild(document.createTextNode(value.description));
              col=0;
              row++;        
            
            }         
          }); 
        }); 

      
        // document.body.appendChild(table);     
        document.getElementById('output').appendChild(table)
      },
      error: function(error) {
        //What do you want to do with the error?
        document.getElementById('output2').innerHTML = "error nene";
      },
    }); 

  }

  tableFillData();
</script>




