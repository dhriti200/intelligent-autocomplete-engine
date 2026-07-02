async function searchWord(){

    document.getElementById("results").innerHTML ="<h3>Searching...</h3>";

    let query=document.getElementById("query").value;

    if(query==="") return;

    const response=await fetch(
        `https://intelligent-autocomplete-engine.onrender.com/search?q=${query}`
    );

    const data=await response.json();
    if(data.results.length===0){

        document.getElementById("results").innerHTML=`
            <h2>No Suggestions Found</h2>
    `;

        return;
}

    const timeMs = (parseInt(data.time_microseconds) / 1000).toFixed(3);

    document.getElementById("stats").innerHTML = `
        <h3>Matches : ${data.matches}</h3>
        <h3>Search Time : ${timeMs} ms</h3>
`;

    let html="";

    data.results.forEach(item=>{

        html+=`
        <div class="card">
            <h3>${item.word}</h3>
            <p>Frequency : ${item.frequency}</p>
        </div>
        `;

    });

    document.getElementById("results").innerHTML=html;

}
document
.getElementById("query")
.addEventListener("keypress",function(e){

    if(e.key==="Enter"){

        searchWord();

    }

});
window.searchWord = searchWord;