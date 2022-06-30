package com.qhy040404.homo

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initView()
    }

    private fun initView(){
        val textView:TextView =findViewById(R.id.textView)
        val button:Button=findViewById(R.id.button)
        val input:EditText=findViewById(R.id.editTextTextPersonName)

        button.setOnClickListener {
            textView.text= BinarySplit(input.text.toString().toInt())
        }
    }

    companion object{
        init {
            System.loadLibrary("homo")
        }
        external fun BinarySplit(x:Int):String?
    }
}