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
  <div id="output">NO DATA 3</div>
  <div id="output2">NO DATA 4</div>
</div>

<script>
   
  function tableCreate(table_id,rows,cols){
    var body = document.body,
        tbl  = document.createElement(table_id);
    /* tbl.style.width  = '200px' ;*/
    /* tbl.style.border = '1px solid black'; */
    /* body.innerHTML = "TITLE"; */

    for(var i = 0; i < rows; i++){
        var tr = tbl.insertRow();  
         
        
        for(var j = 0; j < cols; j++){
            
            if(i == rows){   
            var td = tr.insertCell();               
                break;                
                
            } else {
            
                var td = tr.insertCell();
                /* td.appendChild(document.createTextNode(" yeaah")) ;*/
               /*  var img = document.createElement("img");
                img.src = image;
                td.appendChild(document.createTextNode(title)) ; 
                td.appendChild(img)
                td.appendChild(document.createTextNode(description)); */
                
                
                /* td.style.border = '1px solid black'; */
               
                if(i == rows ){
                    td.setAttribute('rowSpan', '2');
                   
                }

            }            
        }        
        
    }
    /* body.appendChild(tbl) */;
    
    return tbl;
}
  
</script>


<script>

  function tableFillData(){


var url = "https://danieltobon43.pythonanywhere.com/projects";
  // var url = "https://sourceforge.net/projects/kaais/files/stats/json?start_date=2013-08-18&end_date=2018-04-19";


$.ajax({
  method: "GET",
  cache: false,
  url: url,
  dataType: "json",
  success: function(data) {
    // document.getElementById('output').innerHTML = data.total;
    // document.getElementById('output').innerHTML = "rico";
    /* alert(JSON.stringify(data, null, 4)) */    
    

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
                        console.log("name: " + value.name);
                        var td = table.rows[row].cells[0];
          var img = document.createElement("img");
          console.log("url:" + value.url)
          img.src = value.images;
          img.width = 240
          img.height = 100
          img.onclick = function() {
          window.location.href = value.url;}
          td.appendChild(document.createTextNode(value.name)); 
          var br = document.createElement("br");
          td.appendChild(br);
          td.appendChild(img);
          td.appendChild(br);
          td.appendChild(document.createTextNode(value.description));
          td.appendChild(br);
          
          col++;
        
        
        }else{
        var div = document.createElement("div");     
                        console.log("name: " + value.name);
                        var td = table.rows[row].cells[1];
          var img = document.createElement("img");
          img.src = "http://www.google.com/intl/en_com/images/logo_plain.png";
          td.appendChild(document.createTextNode(value.name)) ; 
          td.appendChild(img)
          td.appendChild(document.createTextNode(value.description));
          col=0;
          row++;        
        
        }
                      
       
        
        
                  }); 
        }); 
/* 
    for (var i = 0; i < rows; i++) {   
      for (var j = 0; j < 2; j++) {

        var td = table.rows[i].cells[j];
        var img = document.createElement("img");
        img.src = "http://www.google.com/intl/en_com/images/logo_plain.png";
        td.appendChild(document.createTextNode("title")) ; 
        td.appendChild(img)
        td.appendChild(document.createTextNode("description")); 
        
        }

      
    } */
    
   
    document.body.appendChild(table);
    
    
   /*  var td = table.rows[0].cells[1];
    var img = document.createElement("img");
    img.src = "http://www.google.com/intl/en_com/images/logo_plain.png";
    td.appendChild(document.createTextNode("title")) ; 
    td.appendChild(img)
    td.appendChild(document.createTextNode("description")); 
    
    console.log("res: "+ td);
    document.body.appendChild(table); */
    
       /*
    data.forEach(obj => {
        Object.entries(obj).forEach(([key, value]) => {
        
            var div = document.createElement("div");
            
            
            
            console.log("name: " + value.name)
            
        
           Object.entries(value).forEach(([key, value]) => {
              console.log("test: " + key)
              console.log(`${key}: ${value}`);
              div.innerHTML = value;
               document.body.appendChild(div);
            
            });              
            
            console.log('-------------------');
        
        });
        
            }); 
   
    */
    // document.getElementById('output').innerHTML = table
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




