//get video from html
const video = document.getElementById("js--video");
const photo = document.getElementById("js--photo");

let check = true;

// make variable with array to put data in
let predictedAges = [];
//load the api models from the file models
Promise.all([
    faceapi.nets.tinyFaceDetector.loadFromUri("./models"),
    faceapi.nets.faceLandmark68Net.loadFromUri("./models"),
    faceapi.nets.faceRecognitionNet.loadFromUri("./models"),
    faceapi.nets.faceExpressionNet.loadFromUri("./models"),
    faceapi.nets.ageGenderNet.loadFromUri("./models")
  ]).then(startVideo); //start video in html

//capture video from webcam
function startVideo(){
    navigator.getUserMedia(
        { video: {} },
        stream => (video.srcObject = stream),
        err => console.error(err)
    );
}
    
//when video is playing
video.addEventListener("playing", () => {
    //make a canvas
    const canvas = faceapi.createCanvasFromMedia(video);
    const videoContainer = document.getElementById("js--videoContainer");
    //call on the canvas from as a child from body?
    videoContainer.append(canvas);

    //make settings for the canvas
    const displaySize = { width: video.width, height: video.height };
    //assign settings to canvas
    faceapi.matchDimensions(canvas, displaySize);

    //over an amount of time (100 miliseconds)
    setInterval( async () => {
        //make variable that detects face
        const detections = await faceapi.detectAllFaces(
        video,
        new faceapi.TinyFaceDetectorOptions() //activate api model
        )
        .withFaceLandmarks() //activate api model
        .withFaceExpressions() //activate api model
        .withAgeAndGender(); //activate api model
        const resizedDetections = faceapi.resizeResults(detections,
        displaySize); //make variable that detects a face within display size
      
        canvas.getContext("2d").clearRect(0, 0, canvas.width, canvas.height); //clears retangles when a new one is drawn

        faceapi.draw.drawDetections(canvas, resizedDetections); //draws rectangle where face is detected
        faceapi.draw.drawFaceLandmarks(canvas, resizedDetections); //draws face landmark features
        faceapi.draw.drawFaceExpressions(canvas, resizedDetections); //looks for face expressions and draw it as text

        const age = resizedDetections[0].age; //look at age in the array created through resizedDetections
        const interpolatedAge = interpolateAgePredictions(age); //use function to create predicted age
        //variable to assign settings
        const bottomRight = {
            x: resizedDetections[0].detection.box.bottomRight.x - 60,
            y: resizedDetections[0].detection.box.bottomRight.y
        }

        //draw new info box on the bottom right
        new faceapi.draw.DrawTextField(
            [`${faceapi.utils.round(interpolatedAge, 0)} years`], //use calculated age and print years after
            bottomRight //at bottom right
        ).draw(canvas);
        console.log(resizedDetections);

        
         //after interval 3s
        if(resizedDetections[0].expressions.happy > 0.80 && check === true){ //if the emotion neutral is higher than 0.80
            check = false;
            console.log("happy detected")//print happy
            setTimeout(function(){
                //make screenshot and save as file/put in database
                const ctx = canvas.getContext('2d');
                    
                ctx.drawImage(video, 0, 0, canvas.width, canvas.height);

                
                const data = canvas.toDataURL("image/png");
                console.log(data);
                photo.setAttribute("src", data);
                if (window.navigator.msSaveBlob){
                    window.navigator.msSaveBlob(myCanvas.msToBlob(), "canvas-image.png");
                } else{
                    const a = document.createElement("a");

                    document.body.appendChild(a);
                    a.href = canvas.toDataURL();
                    a.download = "canvas-image.png";
                    a.click();
                    document.body.removeChild(a);
                }
                check = true;  
                console.log("pictured taken"); 
                
        
                
            }, 2000);
              
        }

    }, 100); // do code after 100 miliseconds
})

//function to calculate average age
function interpolateAgePredictions(age){
    predictedAges = [age].concat(predictedAges).slice(0, 30); //measure 30x
    const avgPredictedAge = 
        predictedAges.reduce((total, a) => total + a) / predictedAges.length; //devide by the amount measured
        return avgPredictedAge; //give back result
}

/*
    new things in the code:
    - navigator
    - append()
    - matchDimensions()
    - concat()

    base64 string to image in php

    setTimeout(function(){
        ctx.clearRect(0,0,canvas.width,canvas.height);
    },2000);
*/