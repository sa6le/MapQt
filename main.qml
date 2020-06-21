import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.9
import QtPositioning 5.6
import QtQuick.Controls 2.3
import sable 1.0
Rectangle{
visible: true
width:400
height: 480

Worker{
id:workercpp
}

Plugin {
id: mapPlugin
name: "osm"
}

Map {
id: map

anchors.fill: parent
plugin: mapPlugin
center: QtPositioning.coordinate(51.6574, 39.2130)
zoomLevel: 12

MapItemView {
id:item
model: workercpp.model
delegate: MapQuickItem {
id: delegateMarker
coordinate: QtPositioning.coordinate(model.modelData.Latitude, model.modelData.Longitude)
anchorPoint.x: image.width * 0.5
anchorPoint.y: image.height
sourceItem: Column {
Image { id: image; source: "icons/marker.png" }
Text { text: title; font.bold: true }
}
}

/*
delegate: MapCircle {
id: delegateCircle

center {
latitude: model.modelData.Latitude
longitude: model.modelData.Longitude
}
radius: 160.0
color: 'green'
border.width: 2
}
*/
}
}


}
