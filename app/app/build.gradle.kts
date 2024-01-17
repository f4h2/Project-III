plugins {
    id("com.android.application")
    id("org.jetbrains.kotlin.android")
    id("com.google.gms.google-services")

}

android {
    namespace = "com.example.projectiii"
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.projectiii"
        minSdk = 24
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
    kotlinOptions {
        jvmTarget = "1.8"
    }
}


dependencies {

    implementation("androidx.core:core-ktx:1.9.0")
    implementation("androidx.appcompat:appcompat:1.6.1")
    implementation("com.google.android.material:material:1.11.0")
    implementation("androidx.constraintlayout:constraintlayout:2.1.4")
    implementation("com.google.firebase:firebase-database:20.3.0")
    testImplementation("junit:junit:4.13.2")
    androidTestImplementation("androidx.test.ext:junit:1.1.5")
    androidTestImplementation("androidx.test.espresso:espresso-core:3.5.1")
    implementation(platform("com.google.firebase:firebase-bom:32.7.0"))

    // When using the BoM, you don't specify versions in Firebase library dependencies

    // Add the dependency for the Firebase SDK for Google Analytics
    implementation("com.google.firebase:firebase-analytics")

    // TODO: Add the dependencies for any other Firebase products you want to use
    // See https://firebase.google.com/docs/android/setup#available-libraries
    // For example, add the dependencies for Firebase Authentication and Cloud Firestore
    implementation("com.google.firebase:firebase-auth")
    implementation("com.google.firebase:firebase-firestore")
}
//dependencies {
//    implementation fileTree(org.gradle.internal.impldep.bsh.commands.dir: 'libs', include: ['*.jar'])
//
//    implementation 'com.android.support.constraint:constraint-layout:1.1.3'
//    testImplementation("junit:junit:4.13.2")
//    implementation 'com.google.android.material:material:1.1.0-alpha04'
//    androidTestImplementation 'com.android.support.test:runner:1.0.2'
//    androidTestImplementation("androidx.test.espresso:espresso-core:3.5.1")
//    implementation 'com.google.firebase:firebase-analytics:17.4.3'
//    implementation("com.google.firebase:firebase-database:20.3.0")
//    implementation 'com.google.firebase:firebase-auth:19.3.1'
//    implementation 'com.google.firebase:firebase-core:17.4.2'
//}
