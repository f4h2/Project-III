package com.example.projectiii

import android.app.Activity
import android.os.Bundle
import android.view.View
import android.widget.TextView
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener


class MainActivity : Activity() {
    var mydb: DatabaseReference? = null
    var temp: TextView? = null
    var hum: TextView? = null
    var light: TextView? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        temp = findViewById<View>(R.id.temp) as TextView
        hum = findViewById<View>(R.id.hum) as TextView
        light = findViewById<View>(R.id.light) as TextView
        mydb = FirebaseDatabase.getInstance().reference.child("Sensor")
        try {
            mydb!!.addValueEventListener(object : ValueEventListener {
                override fun onDataChange(dataSnapshot: DataSnapshot) {
                    val tempdata = dataSnapshot.child("temp").value.toString()
                    val humdata = dataSnapshot.child("hum").value.toString()
                    val lightdata = dataSnapshot.child("light").value.toString()
                    temp!!.text = tempdata
                    hum!!.text = humdata
                    light!!.text = lightdata
                }

                override fun onCancelled(error: DatabaseError) {
                    // Failed to read value
                }
            })
        } catch (e: Exception) {
        }
    }
}