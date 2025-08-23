import QtQuick
import QtQuick.Window

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("QML App")

  Rectangle {
    width: parent.width
    height: parent.height
    color: "black"
    Text {
      id: helloText
      text: "Hello, QML!"
      anchors.centerIn: parent
      font.pointSize: 24
      color: "white"
    }
  }
}
