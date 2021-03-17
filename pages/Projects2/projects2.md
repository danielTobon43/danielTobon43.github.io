---
layout: page
title: Projects
subtitle: 
<!-- js: "/js/projects.js" -->
<!-- css: "/assets/css/projects.css" -->
<!-- css: "/assets/css/bootstrap.css" -->
---

<p>Before the script...</p>

<style>
table {
  border-collapse: collapse;
  width: 100%;
  height:200px;
  background-color: #111111; 
  color:white;
}

th, tr, td {
  padding: 0px;
  text-align: center;
  border-bottom: 1px solid #ddd;
  max-width: 55px;
  height:100%;
  background-color: #111111; 
  
}

article,
aside,
details,
figcaption,
figure,
footer,
header,
hgroup,
main,
menu,
nav,
section,
summary {
  display: block;
}

div.relative {
  position: relative;
  left: 0px;
  /*border: 3px solid #73AD21;*/
}



/*text {
  padding: 0px;
  width: 100px;
  height:80px;
  border-bottom: 1px solid #ddd;
  text-align:center;  
  margin:0px 10px;
}*/

img {
  padding: 0px;
  width: 100px;
  height:80px;
  
  vertical-align:top; 
  margin:0px 10px;
  max-width: 900px;
  
}

tr:hover {background-color:'#111111';}
</style>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script>

<div id="container">
  <div id="output">NO DATA 113</div>
  <div id="output2">NO DATA 4</div>
</div>

<script>
   
  function tableCreate(table_id,rows,cols){
    var body = document.body;
    tbl = document.createElement(table_id);

    var total_rows = Math.round(rows/2);
  
    for(var i = 0; i < total_rows; i++){
        var tr = tbl.insertRow();           
        for(var j = 0; j < cols; j++){            
            if(i == total_rows){   
            var td = tr.insertCell();               
                break;                
                
            } else {            
                var td = tr.insertCell();
                if(i == total_rows ){
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

        var key=0
        var rows = 0;
        for(key in data.projects) {
          if(data.projects.hasOwnProperty(key)) {
            rows++;
          }
        }
        
        console.log(rows);     
        data = JSON.stringify([data.projects]);    
        data = JSON.parse(data);
        
        table = tableCreate("table",rows,2);
        
        var row = 0;
        var col = 0;   


        data.forEach(obj => {
          Object.entries(obj).forEach(([key, value]) => {
                      
            if (col == 0){
            
              var div1 = document.createElement("div");  
              var div2 = document.createElement("div"); 
              var div3 = document.createElement("div"); 
              var td = table.rows[row].cells[0];
              var img = document.createElement("img");             
              img.src = value.images;              
              img.onclick = function() {
                window.location.href = value.url;
              }
              div1.appendChild(img);
              div2.appendChild(document.createTextNode(value.name));
              div3.appendChild(document.createTextNode(value.description));
              td.appendChild(div1)
              td.appendChild(div2)
              td.appendChild(div3)
              col++;  
            
            }else{
              var div1 = document.createElement("div");  
              var div2 = document.createElement("div"); 
              var div3 = document.createElement("div");    
              var td = table.rows[row].cells[1];
              var img = document.createElement("img");
              img.src = value.images;
              
              div1.appendChild(img);
              div2.appendChild(document.createTextNode(value.name));
              div3.appendChild(document.createTextNode(value.description));
              td.appendChild(div1)
              td.appendChild(div2)
              td.appendChild(div3)
              
             
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




