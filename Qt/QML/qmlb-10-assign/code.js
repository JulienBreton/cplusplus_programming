var label

function random() {
    return Math.round(Math.random() * 100)
}

function startUp (uiLabel){
    label = uiLabel
}

function updateLabel() {
    label.text = random()
}
