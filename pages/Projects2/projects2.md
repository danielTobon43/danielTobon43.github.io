---
<!-- layout: page -->
title: Projects
subtitle: 
<!-- js: "/js/projects.js" -->
<!-- css: "/assets/css/projects.css" -->
<!-- css: "/assets/css/beautifuljekyll.css" -->
---

<style>
	#table_cv {
	  /*border-collapse: collapse;
	  width: 100%;
	  height:200px;*/
	  /*background-color: #111111; */
	  position: relative;
	  /*color:white;*/
	}

	th, tr, td {
	  /*padding: 0px;*/
	  text-align: center;
	  /*border-bottom: 1px solid #ddd;*/
	  /*max-width: 55px;*/
	  /*height:100%;*/
	  background-color: #111111; 
	  
	}

	img {
	  width: 300px;
	  height:180px;  
	  vertical-align:top; 
	}

	.center{
		margin: auto;
		/*padding: 40px;*/
		display: flex;
  		justify-content: center;
	}

	#DivImage{	
			
  		justify-content: center;
  		border: 3px solid #73AD21;
  		display: block;
		width: 100%;
		height: 100%;
		margin: 0;
		padding: 0;
		text-align: center;
	}

	#subtitle_header{
		  padding: 60px;
		  text-align: left;
		  background: #1abc9c;
		  color: white;
		  font-size: 30px;
	}

	#title_header{
		  padding: 0px;
		  text-align: center;
		  background: #1abc9c;
		  color: white;
		  font-size: 72px;
		  font-family: "Lucida Console", "Courier New", monospace;
	}
</style>

<p style="display: none;" id="numRepos">0</p>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script>

<div id="container">
  <div id="output"></div>
  <div id="output2"></div>
</div>

<script>
   
  function tableCreate(table_id,rows,cols){
    var body = document.body;
    tbl = document.createElement('table');
		tbl.id = table_id;

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
	function groupTable(input_list){
		tbl_element = tableCreate('table_cv',input_list.length,2);
		
		var i = 0, len = input_list.length;
		var row = 0;
    	var col = 0; 
		
	  while (i < len) {
		value = input_list[i];
		
		if (col == 0){

	            
	        var div1 = document.createElement("div");  
	        var div2 = document.createElement("div"); 
	        var div3 = document.createElement("div"); 

	          div1.id = "DivImage";

	          // div1.classList.add('center');
	          div2.classList.add('center');
	          div3.classList.add('center');								

	          var td = tbl_element.rows[row].cells[0];
							console.log("yeah3");
	          var img = document.createElement("img"); 							
							
	          img.src = value.images;              
	          img.onclick = function() {
	            window.location.href = value.url;
	          }
							
	          var a = document.createElement('a');
	          var linkText = document.createTextNode(value.name);
	          a.appendChild(linkText);
	              a.title = value.name;
	              a.href = value.url;
	              div1.appendChild(img);
	              div2.appendChild(a);              
	              div3.appendChild(document.createTextNode(value.description));
	              td.appendChild(div1)
	              td.appendChild(div2)
	              td.appendChild(div3)
	              col++;  

	            
            }else{
              var div1 = document.createElement("div");  
              var div2 = document.createElement("div"); 
              var div3 = document.createElement("div");

              div1.id = "DivImage";   

              div2.classList.add('center');
              div3.classList.add('center');
							console.log("gh");

              var td = tbl_element.rows[row].cells[1];
							console.log("gh");
              var img = document.createElement("img");
              img.src = value.images;
              var a = document.createElement('a');
              var linkText = document.createTextNode(value.name);
              a.appendChild(linkText);
              a.title = value.name;
              a.href = value.url;
              
              div1.appendChild(img);
              div2.appendChild(a);
              div3.appendChild(document.createTextNode(value.description));
              td.appendChild(div1)
              td.appendChild(div2)
              td.appendChild(div3)
              

              col=0;
              row++;        
            
            }
			i++;

	  }	
	return tbl_element;
		
	}
</script>

<script>
	

function getTotalRepos(url){

	var rowsInRepo = 0;

	$.ajax({
      method: "GET",
      cache: false,
      url: url,
      dataType: "json",
	  async : false, 
      success: function(data) {

        var key=0
        var rows = 0;
        for(key in data.projects) {
          if(data.projects.hasOwnProperty(key)) {
            rows++;
          }
        }
        
        //console.log(rows); 
        rowsInRepo = rows;
				//console.log(rowsInRepo);

      },
      
    });  
		
		return rowsInRepo;
}

</script>

<script>

  function tableFillData(){
    var url = "https://danieltobon43.pythonanywhere.com/projects";   

    var rowsInRepo = getTotalRepos(url);		
	console.log("total repos: ",rowsInRepo);
		
    var totalRepos = document.getElementById("numRepos");
	var contentVar = totalRepos.textContent;
	console.log("number in div: ",contentVar);
	if (contentVar == 0 || contentVar < rowsInRepo){
	    console.log("ADDING NEW REPOS...");
			//document.getElementById("numRepos").textContent = 32;
			
		 

	    $.ajax({
	      method: "GET",
	      cache: false,
	      url: url,
	      dataType: "json",
	      async : false, 
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
					
					var list_cv_projects = [];
					
					data.forEach(obj => {
	          Object.entries(obj).forEach(([key, value]) => {
	          		if (value.topics.includes('opencv')){
									console.log("repo: " + value.name + " has topic: opencv");
									list_cv_projects.push(value);
								}          	
	          }); 
	        }); 

			var title = document.createElement('h1');
	        title.textContent  = "Projects";
	        

			// var title = document.createElement('h');
			// title = "Projects"
			title.id = 'title_header';
	        var sub_div0 = document.createElement('div');
			sub_div0.appendChild(title);
	        document.getElementById('output').appendChild(sub_div0);
					
			var sub_title = document.createElement('h');
			sub_title.id = 'subtitle_header';

	        sub_title = "Computer Vision";
	        var sub_div1 = document.createElement('div');
			sub_div1.appendChild(document.createTextNode(sub_title));
	        document.getElementById('output').appendChild(sub_div1);
					
			tbl2 = groupTable(list_cv_projects);

			var sub_div2 = document.createElement('div');
			sub_div2.appendChild(tbl2);
			document.getElementById('output').appendChild(sub_div2);

			sub_title = "Other";
	        var sub_div3 = document.createElement('div');
			sub_div3.appendChild(document.createTextNode(sub_title));
	        document.getElementById('output').appendChild(sub_div3);
			
			console.log(list_cv_projects);
			var i = 0, len = list_cv_projects.length;
			while (i < len) {
					// your code
					i++;
					console.log("yea");
			}
					
	        data.forEach(obj => {
	          Object.entries(obj).forEach(([key, value]) => {

	          	

	          		if(value.name=='danieltobon43.github.io' || value.name == 'danielTobon43'){
	          			return;
	          		}
	                      
		            if (col == 0){
		            
		              var div1 = document.createElement("div");  
		              var div2 = document.createElement("div"); 
		              var div3 = document.createElement("div"); 
									<!-- div2.setAttribute("id", "Div2"); -->
									
									div2.id = "Div2";						
								
								

		              // div1.classList.add('center');
		              div2.classList.add('center');
		              div3.classList.add('center');

		              var td = table.rows[row].cells[0];
		              var img = document.createElement("img");             
		              img.src = value.images;              
		              img.onclick = function() {
		                window.location.href = value.url;
		              }
		              var a = document.createElement('a');
		              var linkText = document.createTextNode(value.name);
		              a.appendChild(linkText);
		              a.title = value.name;
		              a.href = value.url;
		              div1.appendChild(img);
		              div2.appendChild(a);              
		              div3.appendChild(document.createTextNode(value.description));
		              td.appendChild(div1)
		              td.appendChild(div2)
		              td.appendChild(div3)
		              col++;  
		            
		            }else{
		              var div1 = document.createElement("div");  
		              var div2 = document.createElement("div"); 
		              var div3 = document.createElement("div");    

		              div2.classList.add('center');
		              div3.classList.add('center');

		              var td = table.rows[row].cells[1];
		              var img = document.createElement("img");
		              img.src = value.images;
		              var a = document.createElement('a');
		              var linkText = document.createTextNode(value.name);
		              a.appendChild(linkText);
		              a.title = value.name;
		              a.href = value.url;
		              
		              div1.appendChild(img);
		              div2.appendChild(a);
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
	        document.getElementById('output').appendChild(table);
	        // document.getElementById('output').innerHTML = table;
	      },
	      error: function(error) {
	        //What do you want to do with the error?
	        document.getElementById('output2').innerHTML = "error nene";
	      },
	    }); 
		totalRepos.textContent = rowsInRepo;

	}else{
			console.log("NOT NEW REPOS!");
	     
	        return false;
	} 

  }
  

 tableFillData(); 
</script>

<script>
  function urlRepo(text,url) {
  var str = text;
  var result = str.link(url);
  return result;
}
</script>




