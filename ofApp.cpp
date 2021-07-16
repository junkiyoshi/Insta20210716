#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(2);
	ofEnableDepthTest();

	this->font_size = 80;
	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);

	string word = "ABCDEFGHEJKLMNOPQRSTUVWXYZ!";
	int sample_count = 180;
	auto noise_param = ofRandom(1000);
	
	for (int i = 0; i < word.size(); i++) {

		ofPath chara_path = this->font.getCharacterAsPoints(word[i], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			if (outline_index != 0) { ofNextContour(true); }

			auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
			for (auto& vertex : vertices) {

				auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
				auto rotation_y = glm::rotate(glm::mat4(), (i * 13.5f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;

				auto noise_value = ofNoise(noise_param, i * 0.5 + ofGetFrameNum() * 0.02);
				float param = noise_value;
				location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

				if (location.y > 0) {
				
					ofVertex(location - glm::vec3(0, 100, 0));
				}
			}
		}
		ofEndShape();

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			if (outline_index != 0) { ofNextContour(true); }

			auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
			for (auto& vertex : vertices) {

				auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
				auto rotation_y = glm::rotate(glm::mat4(), (i * 13.5f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;

				auto noise_value = ofNoise(noise_param, i * 0.5 + ofGetFrameNum() * 0.02);
				float param = noise_value;
				location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

				if (location.y > 0) {

					ofVertex(location - glm::vec3(0, 100, 0));
				}
			}
		}
		ofEndShape();
	}

	for (int i = 0; i < word.size(); i++) {

		ofPath chara_path = this->font.getCharacterAsPoints(word[i], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			if (outline_index != 0) { ofNextContour(true); }

			auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
			for (auto& vertex : vertices) {

				auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
				auto rotation_y = glm::rotate(glm::mat4(), (i * 13.5f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;

				auto noise_value = ofNoise(noise_param, i * 0.5 + ofGetFrameNum() * 0.02);
				float param = noise_value;
				location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

				if (location.y < 0) {

					ofVertex(location + glm::vec3(0, 100, 0));
				}
			}
		}
		ofEndShape();

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			if (outline_index != 0) { ofNextContour(true); }

			auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
			for (auto& vertex : vertices) {

				auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
				auto rotation_y = glm::rotate(glm::mat4(), (i * 13.5f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;

				auto noise_value = ofNoise(noise_param, i * 0.5 + ofGetFrameNum() * 0.02);
				float param = noise_value;
				location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

				if (location.y < 0) {

					ofVertex(location + glm::vec3(0, 100, 0));
				}
			}
		}
		ofEndShape();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}